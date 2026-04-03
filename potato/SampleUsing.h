std::unordered_map<std::string, std::unordered_map<std::string, double>> process_potatoes() {

    std::vector<std::string> headers = {
        "Образец", "№ по каталогу ВИГРР", "Происхождение",
        "Товарных клубней в клоне, шт.", "Нетоварных клубней в клоне, шт.",
        "Масса товарного клубня, г", "Масса нетоварного клубня, г",
        "Клубней в клоне, шт", "Товарность", "Урожайность",
        "Форма клубня", "Окраска кожуры", "Окраска мякоти",
        "Глубина глазков", "Глубина столонного следа",
        "Поверхность кожуры клубня", "Разваримость клубней",
        "Консистенция мякоти", "Рассыпчатость", "Водянистость клубней",
        "Запах варёного картофеля", "Вкус",
        "Потемнение мякоти сырого картофеля", "Потемнение мякоти варёного картофеля"
    };

	std::vector<std::vector<std::wstring>> Sample = GetSample();

	json Sampl = ReadJSON("Sample.json", "Столовый стандарт");

    auto weights = Sampl["weights"].get<std::unordered_map<std::string, double>>();

    std::vector<std::string> selectedTraits;
    std::vector<int> number;

    for (auto const& pair : weights) {
        selectedTraits.push_back(pair.first);
    }

    for (int i = 0; i < selectedTraits.size(); i++) {
        for (int j = 0; j < headers.size(); j++) {
            if (headers[j] == selectedTraits[i]) {
                number.push_back(j);
            }
        }
    }  

    std::unordered_map<std::string, std::unordered_map<std::string, double>> DataBD;

    for (int i = 0; i < Sample.size(); i++) {
        std::string objectName = utf16_to_utf8(Sample[i][0]);

        std::unordered_map<std::string, double> currentData;

        for (int j = 0; j < number.size(); j++) {
            int colIndex = number[j];

            std::wstring wideValue = Sample[i][colIndex];
            if (wideValue.empty()) continue;

            std::string cellValueRaw = utf16_to_utf8(wideValue);
            double value = std::stod(cellValueRaw);

            std::string traitName = selectedTraits[j];
            currentData[traitName] = value;

        }

        if (!currentData.empty()) {
            DataBD[objectName] = currentData;
        }
    }

    return DataBD;
}

std::unordered_map<std::string, Trait> initTraits() {
    std::unordered_map<std::string, Trait> t;
   
    t["Вкус"] = Trait("Вкус", Trait::LargerBetter, 1, 9, 0, 0, "балл");
    t["Товарность"] = Trait("Товарность", Trait::LargerBetter, 50, 100, 0, 0, "%");
    t["Урожайность"] = Trait("Урожайность", Trait::LargerBetter, 1, 6, 0, 0, "ц/га");
    t["Форма клубня"] = Trait("Форма клубня", Trait::LargerBetter, 1, 9);
    t["Потемнение мякоти"] = Trait("Потемнение мякоти", Trait::SmallerBetter, 1, 9);
    t["Развариваемость"] = Trait("Развариваемость", Trait::LargerBetter, 1, 9);
    t["Устойчивость к фитофторозу"] = Trait("Устойчивость к фитофторозу", Trait::LargerBetter, 1, 9);
    return t;
}

void Sampling() {
    // 1. Получаем данные
    auto DataBD = process_potatoes();

    // 2. Создаем вектор объектов
    std::vector<Variety> varieties;
    for (auto const& item : DataBD) {
        const std::string& name = item.first;
        const std::unordered_map<std::string, double>& traitsMap = item.second;

        Variety v(name);
        for (auto const& traitPair : traitsMap) {
            v.setTrait(traitPair.first, traitPair.second);
        }
        varieties.push_back(v);
    }

    auto traitsDict = initTraits();

    // 3. Загружаем шаблон
    json Sampl = ReadJSON("Sample.json", "Столовый стандарт");

    ExpertTemplate universal("Столовый стандарт", "Критерий качества", EvaluationMethod::WSM);

    if (Sampl.contains("weights") && Sampl["weights"].is_object()) {
        for (auto& [traitName, weightValue] : Sampl["weights"].items()) {
            if (weightValue.is_number()) {
                universal.setWeight(traitName, weightValue.get<double>());
            }
        }
    }

    // 4. Расчет рейтинга
    // Используем указатель на Variety (Variety*), чтобы не копировать объекты целиком
    std::vector<std::pair<Variety, double>> results;
    for (auto& v : varieties) {
        double score = universal.evaluate(v, traitsDict);
        results.push_back({ v, score });
    }

    // 5. Сортировка
    std::sort(results.begin(), results.end(), [](const std::pair<Variety, double>& a, const std::pair<Variety, double>& b) {
        return a.second > b.second;
        });

    std::ofstream out("txt.txt");
    if (out.is_open()) {
        for (const auto& res : results) {
            if (res.second > 0.350) {
                // res.first - это объект Variety
                printRadarChartToFile(out, res.first, universal, traitsDict);
                out << "\n" << std::string(60, '=') << "\n"; // Разделитель между сортами
            }
        }
        out.close();
    }
}
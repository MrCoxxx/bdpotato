json process_potatoes() {

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

	json Sampl = ReadJSON("Sample.json", "name13");

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

    return json(DataBD);
}
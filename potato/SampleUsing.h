std::vector<std::wstring> a() {

    std::vector<std::string> headers; 
    headers.push_back("Образец");
    headers.push_back("№ по каталогу ВИГРР");
    headers.push_back("Происхождение");
    headers.push_back("Товарных клубней в клоне, шт.");
    headers.push_back("Нетоварных клубней в клоне, шт.");
    headers.push_back("Масса товарного клубня, г");
    headers.push_back("Масса нетоварного клубня, г");
    headers.push_back("Клубней в клоне, шт");
    headers.push_back("Товарность, %");
    headers.push_back("Урожайность, кг/м2");
    headers.push_back("Форма клубня");
    headers.push_back("Окраска кожуры");
    headers.push_back("Окраска мякоти");
    headers.push_back("Глубина глазков");
    headers.push_back("Глубина столонного следа");
    headers.push_back("Поверхность кожуры клубня");
    headers.push_back("Разваримость клубней");
    headers.push_back("Консистенция мякоти");
    headers.push_back("Рассыпчатость");
    headers.push_back("Водянистость клубней");
    headers.push_back("Запах варёного картофеля");
    headers.push_back("Вкус варёного картофеля");
    headers.push_back("Потемнение мякоти сырого картофеля");
    headers.push_back("Потемнение мякоти варёного картофеля");

	std::vector<std::vector<std::wstring>> Sample = GetSample();

	json Sampl = ReadJSON("Sample.json", "name1");

	std::unordered_map<std::string, double> weights = Sampl["weights"].get<std::unordered_map<std::string, double>>();

    std::vector<std::string> selectedTraits;
    std::vector<double> weight;
    std::vector<int> number;

    for (auto const& pair : weights) {
        selectedTraits.push_back(pair.first);
        weight.push_back(pair.second);
    }

    for (int i = 0; i < selectedTraits.size(); i++) {
        for (int j = 0; j < headers.size(); j++) {
            headers[j] == selectedTraits[i];
            number[i] = j;
        }
    }

    std::unordered_map<std::string, double> DataBD;

    for (int i = 0; i < Sample.size(); i++){

    }

	return Sampl; 
}
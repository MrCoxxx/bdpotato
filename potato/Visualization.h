void printRadarChartToFile(std::ostream& os, const Variety& variety, const ExpertTemplate& pattern,
    const std::unordered_map<std::string, Trait>& traitsDict) {

    os << "\n--- Анализ сорта: " << variety.name << " ---\n";

    // Используем pattern.selectedTraits для последовательного вывода
    for (const auto& traitName : pattern.selectedTraits) {
        auto it = traitsDict.find(traitName);
        if (it == traitsDict.end()) continue;

        double val = variety.getTrait(traitName);
        double norm = it->second.normalize(val);

        // Длина графической полоски (30 символов максимум)
        int barLength = static_cast<int>(norm * 30);

        os << std::setw(30) << std::left << traitName << " |";
        for (int i = 0; i < 30; ++i) {
            os << (i < barLength ? "█" : "░");
        }

        os << "| " << std::fixed << std::setprecision(2) << norm
            << " (исходное значение: " << val << ")\n";
    }

    // Вызов метода оценки (evaluate)
    os << "Интегральный показатель: " << std::fixed << std::setprecision(4)
        << pattern.evaluate(variety, traitsDict) << "\n";
}
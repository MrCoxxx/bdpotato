enum class EvaluationMethod { WSM, Harrington };

class ExpertTemplate {
public:
    std::string name;
    std::string description;
    EvaluationMethod method;
    std::unordered_map<std::string, double> weights;
    std::vector<std::string> selectedTraits;

    ExpertTemplate() = default;
    ExpertTemplate(const std::string& n, const std::string& desc, EvaluationMethod m)
        : name(n), description(desc), method(m) {}

    void setWeight(const std::string& trait, double w) {
        weights[trait] = w;
        if (std::find(selectedTraits.begin(), selectedTraits.end(), trait) == selectedTraits.end()) {
            selectedTraits.push_back(trait);
        }
    }

    double evaluate(const Variety& variety, const std::unordered_map<std::string, Trait>& traitsDict) const {
        if (weights.empty()) return 0.0;

        if (method == EvaluationMethod::WSM) {
            double weightedSum = 0.0;
            double totalWeight = 0.0;

            for (const auto& [traitName, weightValue] : weights) {
                auto traitIt = traitsDict.find(traitName);
                if (traitIt == traitsDict.end()) continue;

                double traitVal = variety.getTrait(traitName);
                // Нормализация (0-1)
                weightedSum += weightValue * traitIt->second.normalize(traitVal);
                totalWeight += weightValue;
            }
            return (totalWeight > 0) ? (weightedSum / totalWeight) : 0.0;
        }
        else { // Harrington
            double geometricProduct = 1.0;
            double totalWeight = 0.0;
            bool hasData = false;

            for (const auto& [traitName, weightValue] : weights) {
                auto traitIt = traitsDict.find(traitName);
                if (traitIt == traitsDict.end()) continue;

                double traitVal = variety.getTrait(traitName);
                double desirability = DesirabilityFunction::compute(traitVal, traitIt->second);

                // Защита от полного обнуления в Harrington
                if (desirability <= 0) desirability = 0.0001;

                geometricProduct *= std::pow(desirability, weightValue);
                totalWeight += weightValue;
                hasData = true;
            }

            if (!hasData || totalWeight == 0) return 0.0;
            return std::pow(geometricProduct, 1.0 / totalWeight);
        }
    }

    void removeWeight(const std::string& trait) {
        auto it = weights.find(trait);
        if (it != weights.end()) {
            weights.erase(it);
            selectedTraits.erase(std::remove(selectedTraits.begin(), selectedTraits.end(), trait), selectedTraits.end());
        }
    }

};
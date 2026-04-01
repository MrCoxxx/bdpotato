// ----------------------------- Класс признака (Trait) -----------------------------
class Trait {
public:
    std::string name;
    enum Direction { LargerBetter, SmallerBetter, TargetRange };
    Direction direction;
    double minValue;
    double maxValue;
    double targetLow;
    double targetHigh;
    std::string unit;

    Trait() = default;
    Trait(const std::string& n, Direction d, double minV, double maxV, double tLow = 0, double tHigh = 0, const std::string& u = "")
        : name(n), direction(d), minValue(minV), maxValue(maxV), targetLow(tLow), targetHigh(tHigh), unit(u) {}

    double normalize(double value) const {
        if (maxValue == minValue) return 1.0;
        if (direction == LargerBetter) {
            return (value - minValue) / (maxValue - minValue);
        }
        else if (direction == SmallerBetter) {
            return (maxValue - value) / (maxValue - minValue);
        }
        else { // TargetRange
            if (value < targetLow) return (value - minValue) / (targetLow - minValue);
            else if (value > targetHigh) return (maxValue - value) / (maxValue - targetHigh);
            else return 1.0;
        }
    }
};

// ----------------------------- Класс сорта (Variety) -----------------------------
class Variety {
public:
    std::string name;
    std::unordered_map<std::string, double> traits;

    Variety() = default;
    Variety(const std::string& n) : name(n) {}
    void setTrait(const std::string& traitName, double value) { traits[traitName] = value; }

    double getTrait(const std::string& traitName) const {
        auto it = traits.find(traitName);
        if (it != traits.end()) return it->second;
        return 0.0; // Возвращаем 0, если признак не задан
    }
};
class DesirabilityFunction {
public:
    static double compute(double x, const Trait& trait) {
        if (trait.direction == Trait::LargerBetter) {
            if (x <= trait.minValue) return 0.01; // Избегаем абсолютного нуля для Harrington
            if (x >= trait.maxValue) return 1.0;
            return (x - trait.minValue) / (trait.maxValue - trait.minValue);
        }
        else if (trait.direction == Trait::SmallerBetter) {
            if (x >= trait.maxValue) return 0.01;
            if (x <= trait.minValue) return 1.0;
            return (trait.maxValue - x) / (trait.maxValue - trait.minValue);
        }
        else {
            if (x < trait.minValue || x > trait.maxValue) return 0.01;
            if (x >= trait.targetLow && x <= trait.targetHigh) return 1.0;
            if (x < trait.targetLow) return (x - trait.minValue) / (trait.targetLow - trait.minValue);
            else return (trait.maxValue - x) / (trait.maxValue - trait.targetHigh);
        }
    }
};
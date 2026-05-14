#include <iostream>
#include <cmath>
#include <random>

// Divine Math Engine: Server-Authoritative Core
// Handles deterministic probability curves and evil scoring logic

class DivineMathEngine {
public:
    struct DivineResults {
        bool isDisaster;
        bool isBlessing;
        double evilScoreAdjustment;
    };

    // Calculates probabilities based on current evil threshold
    // Uses a deterministic seed for server-side consistency
    DivineResults CalculateDivineEvent(double currentEvil, double disasterProb, double blessingProb, uint32_t seed) {
        std::mt19937 gen(seed);
        std::uniform_real_distribution<> dis(0.0, 1.0);

        double roll = dis(gen);
        DivineResults results = {false, false, 0.0};

        // Logic: High evil increases disaster probability
        double effectiveDisasterProb = disasterProb * (1.0 + (currentEvil / 100.0));

        if (roll < effectiveDisasterProb) {
            results.isDisaster = true;
            results.evilScoreAdjustment = 5.0; // Increased evil from disaster
        } else if (roll < (effectiveDisasterProb + blessingProb)) {
            results.isBlessing = true;
            results.evilScoreAdjustment = -2.0; // Decreased evil from blessing
        }

        return results;
    }
};

#include "DivineMathEngine.cpp"
#include <cassert>
#include <iostream>

// CI/CD Unit Test: Divine Probability Curves
// Ensures mathematical integrity of the Divine Math Engine

int main() {
    DivineMathEngine engine;
    
    // Test Case 1: Deterministic results with constant seed
    // Seed 42, Evil 50, Disaster 0.12, Blessing 0.08
    auto res1 = engine.CalculateDivineEvent(50.0, 0.12, 0.08, 42);
    auto res2 = engine.CalculateDivineEvent(50.0, 0.12, 0.08, 42);
    
    assert(res1.isDisaster == res2.isDisaster);
    assert(res1.isBlessing == res2.isBlessing);
    assert(res1.evilScoreAdjustment == res2.evilScoreAdjustment);
    
    // Test Case 2: High Evil Scaling
    // Increasing evil should increase the likelihood of disasters
    int disasterCountLowEvil = 0;
    int disasterCountHighEvil = 0;
    int iterations = 1000;
    uint32_t baseSeed = 12345;

    for (int i = 0; i < iterations; ++i) {
        auto resLow = engine.CalculateDivineEvent(0.0, 0.12, 0.08, baseSeed + i);
        if (resLow.isDisaster) disasterCountLowEvil++;

        auto resHigh = engine.CalculateDivineEvent(500.0, 0.12, 0.08, baseSeed + i);
        if (resHigh.isDisaster) disasterCountHighEvil++;
    }

    std::cout << "Low Evil Disasters: " << disasterCountLowEvil << std::endl;
    std::cout << "High Evil Disasters: " << disasterCountHighEvil << std::endl;

    assert(disasterCountHighEvil > disasterCountLowEvil);

    std::cout << "All Divine Probability Unit Tests Passed!" << std::endl;
    return 0;
}

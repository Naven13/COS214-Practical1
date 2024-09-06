#include "FertilizerDecorator.h"
#include <iostream>

void FertilizerDecorator::increaseProduction() {
    yieldMultiplier = 2;
    std::cout << "Fertilizer applied, yield is doubled!" << std::endl;
}

int FertilizerDecorator::harvest() {
    // Access the soilState via the decorated FarmUnit
    SoilState* currentSoilState = wrapee->getSoilState();

    if (currentSoilState) {
        // Call the harvestCrops() method from the SoilState
        currentSoilState->harvestCrops();

        // Get the base yield from the wrapped FarmUnit
        int baseYield = wrapee->getCurrentStorageCapacity();  // Or a method that returns base yield

        // Modify the yield using the multiplier
        int enhancedYield = baseYield * yieldMultiplier;

        // Store the enhanced yield in the decorated FarmUnit
        if (wrapee->hasStorageSpace(enhancedYield)) {
            wrapee->storeCrops(enhancedYield);
            std::cout << "Harvested " << enhancedYield << " crops with fertilizer boost." << std::endl;
            return enhancedYield;
        } else {
            std::cout << "Not enough storage space for the enhanced crops. Consider building a new barn." << std::endl;
            return 0;
        }
    } else {
        std::cerr << "Error: No soil state available." << std::endl;
        return 0;
    }
}

#include "FruitfulSoil.h"

#include "FloodedSoil.h"

std::string & FruitfulSoil::getName() {
    return this->name;
}

void FruitfulSoil::rain() {
    this->farmUnit->changeSoilState(new FloodedSoil(*this->farmUnit));
}

void FruitfulSoil::harvestCrops() {
    // Assume farmUnit is a pointer to a CropField or FarmUnit and is accessible
    int harvestYield = 3; // Fruitful soil has triple the normal yield
    int spaceNeeded = harvestYield; // Amount of space needed for this harvest

    // Check if the farm unit has enough storage space for the harvested crops
    if (farmUnit->hasStorageSpace(spaceNeeded)) {
        farmUnit->storeCrops(harvestYield); // Store the harvested crops
        std::cout << "FruitfulSoil: " << harvestYield << " crops harvested and stored." << std::endl;
    } else {
        std::cout << "FruitfulSoil: Not enough space for harvest. Consider building a new barn." << std::endl;
    }
}

void FruitfulSoil::fertilize() {
    //does nothing
}

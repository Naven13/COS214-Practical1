#include "DrySoil.h"

#include "FruitfulSoil.h"

std::string & DrySoil::getName() {
    return this->name;
}

void DrySoil::rain() {
    this->farmUnit->changeSoilState(new FruitfulSoil(*this->farmUnit));
}

void DrySoil::harvestCrops() {
    int harvestYield = 1; // Dry soil has minimal yield
    int spaceNeeded = harvestYield; // Amount of space needed for this harvest

    // Check if the farm unit has enough storage space for the harvested crops
    if (farmUnit->hasStorageSpace(spaceNeeded)) {
        farmUnit->storeCrops(harvestYield); // Store the harvested crops
        std::cout << "Crops harvested and stored." << std::endl;
    } else {
        std::cout << "Not enough space for harvest. Consider building a new barn." << std::endl;
    }
}

void DrySoil::fertilize() {
    this->farmUnit->changeSoilState(new FruitfulSoil(*this->farmUnit));
}

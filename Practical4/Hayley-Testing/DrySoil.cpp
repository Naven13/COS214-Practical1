#include "DrySoil.h"

#include "FruitfulSoil.h"

std::string & DrySoil::getName() {
    return this->name;
}

void DrySoil::rain() {
    this->farmUnit->changeSoilState("Fruitful");
}

void DrySoil::harvestCrops() {
    int spaceNeeded = farmUnit->getCropType().harvestYield;
    if(farmUnit->hasStorageSpace(spaceNeeded)) {
        this->farmUnit->storeCrops(1);
    } else {
        std::cout << "More space required for harvest, build a new barn." <<std::endl;
    }
}

void DrySoil::fertilize() {
    this->farmUnit->changeSoilState("Fruitful");
}

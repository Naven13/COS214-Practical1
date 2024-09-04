#include "CropField.h"

struct FarmUnit::pImplFarmUnit {
    int totalCapacity;
    int surfaceArea;
    Crop crop;
    SoilState *soilState;
    int currentCapacity = 0;

    pImplFarmUnit(int totalCapacity, int surfaceArea, Crop crop,
                  SoilState &soilState) : totalCapacity(totalCapacity), soilState(&soilState), surfaceArea(surfaceArea),
                                          crop(crop){}
};

int CropField::getTotalcapacity() {
    return this->impl->totalCapacity;
}

int CropField::getSurfaceArea() {
    return this->impl->surfaceArea;
}

std::string & CropField::getSoilStateName() {
    return this->impl->soilState->getName();
}

Crop CropField::getCropType() {
    return this->impl->crop;
}

FarmIterator CropField::end() {

}

FarmIterator CropField::begin() {

}

void CropField::printFarm() {
}

void CropField::changeSoilState(SoilState &soilState) {
    //delete the current state
    delete this->impl->soilState;
    //add the new state
    this->impl->soilState = &soilState;
}

void CropField::addFarmUnit(FarmUnit *unit) {
}

void CropField::removeFarmUnit(FarmUnit *unit) {
}

FarmIterator CropField::getIterator() {
}

void CropField::storeCrops(int harvestBonus) {
    this->impl->currentCapacity += (this->impl->crop.harvestYield*harvestBonus);
}

int CropField::getCurrentStorageCapacity() {
    return this->impl->currentCapacity();
}

bool CropField::hasStorageSpace(int spaceNeeded) {
    return (this->impl->currentCapacity()+spaceNeeded) <= this->impl->totalCapacity();
}

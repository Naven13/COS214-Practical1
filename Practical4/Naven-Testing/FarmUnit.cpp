#include "FarmUnit.h"
#include "Truck.h"
#include "Crop.h"

// Full definition of pImplFarmUnit
struct FarmUnit::pImplFarmUnit {
    int totalCapacity;
    int surfaceArea;
    Crop crop;
    SoilState *soilState;
    int currentCapacity = 0;
    std::vector<Truck*> observers;

    pImplFarmUnit(int totalCapacity, int surfaceArea, Crop crop, SoilState &soilState)
        : totalCapacity(totalCapacity), surfaceArea(surfaceArea), crop(crop), soilState(&soilState) {}
};

// Constructor implementation
FarmUnit::FarmUnit(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState) {
    Crop crop(cropType);
    this->impl = std::make_unique<pImplFarmUnit>(totalCapacity, surfaceArea, crop, soilState);
}

// Destructor implementation
FarmUnit::~FarmUnit() = default;

// Other member function implementations...
SoilState* FarmUnit::getSoilState() const {
    return soilState;
}
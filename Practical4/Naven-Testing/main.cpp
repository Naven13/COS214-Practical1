#include <iostream>
#include "CropField.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "Crop.h"

// Dummy SoilState to initialize the CropField temporarily
class DummySoilState : public SoilState {
public:
    DummySoilState(FarmUnit& farmUnit) : SoilState(farmUnit, "Dummy Soil") {}

    std::string &getName() override {
        static std::string name = "Dummy Soil";
        return name;
    }

    void rain() override {}
    void harvestCrops() override {}
    void fertilize() override {}
};

int main() {
    // Create a CropType (e.g., Corn)
    CropType cropType = Corn;

    // Create a DummySoilState to temporarily initialize the CropField
    CropField* cropFieldPtr = new CropField(100, 50, cropType, *(new DummySoilState(*cropFieldPtr)));

    // Now create DrySoil and associate it with the CropField
    DrySoil drySoil(*cropFieldPtr);  // Pass the CropField reference to DrySoil
    cropFieldPtr->changeSoilState(drySoil);  // Update the soil state to DrySoil

    // Test: Get and print soil state name
    std::cout << "Initial Soil State: " << cropFieldPtr->getSoilStateName() << std::endl;

    // Test: Harvest crops in DrySoil
    std::cout << "Harvesting crops in DrySoil..." << std::endl;
    drySoil.harvestCrops();

    // Now create FruitfulSoil and associate it with the CropField
    std::cout << "\nChanging soil state to FruitfulSoil..." << std::endl;
    FruitfulSoil fruitfulSoil(*cropFieldPtr);
    cropFieldPtr->changeSoilState(fruitfulSoil);  // Change to FruitfulSoil

    // Test: Get and print soil state name
    std::cout << "Soil State: " << cropFieldPtr->getSoilStateName() << std::endl;

    // Test: Harvest crops in FruitfulSoil (should yield 3x crops)
    std::cout << "Harvesting crops in FruitfulSoil..." << std::endl;
    fruitfulSoil.harvestCrops();

    // Simulate rain to transition from FruitfulSoil to FloodedSoil
    std::cout << "\nSimulating rain to transition to FloodedSoil..." << std::endl;
    fruitfulSoil.rain();  // This should change the soil state to FloodedSoil

    // Test: Get and print soil state name after rain
    std::cout << "Soil State after rain: " << cropFieldPtr->getSoilStateName() << std::endl;

    // Test: Harvest crops in FloodedSoil (should not allow harvest)
    std::cout << "Attempting to harvest crops in FloodedSoil..." << std::endl;
    cropFieldPtr->getSoil()->harvestCrops(); // No crops should be harvested in FloodedSoil
    // Check the current storage capacity after all operations
    std::cout << "\nCurrent Storage Capacity: " << cropFieldPtr->getCurrentStorageCapacity() << std::endl; 

    return 0;
}

#ifndef CROPFIELD_H
#define CROPFIELD_H

#include <string>
#include <vector>
#include "FarmComposite.h"

/**
 * @class CropField
 * @brief Represents a crop field within a farm, derived from `FarmComposite` and `FarmUnit`.
 */
class CropField : public FarmComposite {
public:
    CropField(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState);

    int getTotalcapacity() override;
    int getSurfaceArea() override;
    std::string &getSoilStateName() override;
    Crop getCropType() override;
    void printFarm() override;
    void changeSoilState(SoilState &soilState) override;
    void addFarmUnit(std::shared_ptr<FarmUnit> unit) override;
    void removeFarmUnit(std::shared_ptr<FarmUnit> unit) override;
    std::unique_ptr<FarmIterator> getIterator() override;
    void storeCrops(int harvestBonus) override;
    int getCurrentStorageCapacity() override;
    bool hasStorageSpace(int spaceNeeded) override;
    bool isComposite() const override;
    std::vector<std::shared_ptr<FarmUnit>> getChildren() const override;
    void buyTruck(Truck& truck) override;
    void sellTruck(Truck& truck) override;
    void callTruck(Event e) override;
    void fertilizeCrops() override;
    void collectCrops() override;

private:
    std::vector<std::shared_ptr<FarmUnit>> farms;  // Stores child units
};

#endif // CROPFIELD_H

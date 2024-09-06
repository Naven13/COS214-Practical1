#ifndef FARMUNIT_H
#define FARMUNIT_H

#include "Iterator.h"
#include <memory>
#include <vector>
#include "Crop.h"
#include "TraversalStrategy.h"
#include "FarmIterator.h"
#include "SoilState.h"
#include "Truck.h"
#include "Event.h"

class Truck;
class SoilState;
class FarmIterator;

/**
 * @brief Abstract base class representing the component for the composite pattern
 */
class FarmUnit {
public:
    FarmUnit(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState);
    FarmUnit();
    virtual ~FarmUnit();

    virtual int getTotalcapacity() = 0;
    virtual std::string &getSoilStateName() = 0;
    virtual Crop getCropType() = 0;
    virtual int getSurfaceArea() = 0;
    virtual void changeSoilState(SoilState &soilState) = 0;
    virtual void storeCrops(int harvestBonus = 1) = 0;
    virtual int getCurrentStorageCapacity() = 0;
    virtual bool hasStorageSpace(int spaceNeeded) = 0;
    virtual void printFarm() = 0;
    virtual std::unique_ptr<FarmIterator> getIterator() = 0;
    virtual void buyTruck(Truck& truck) = 0;
    virtual void sellTruck(Truck& truck) = 0;
    virtual void callTruck(Event e) = 0;
    virtual void fertilizeCrops() = 0;
    virtual void collectCrops() = 0;
    SoilState* getSoilState() const;

    // Composite-related methods
    virtual bool isComposite() const { return false; }
    virtual std::vector<std::shared_ptr<FarmUnit>> getChildren() const { return {}; }

protected:
    struct pImplFarmUnit;  // Forward declaration
    std::unique_ptr<pImplFarmUnit> impl;  // PIMPL idiom

    SoilState* soilState;
};

#endif // FARMUNIT_H

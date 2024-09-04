#ifndef FARMCOMPOSITE_H
#define FARMCOMPOSITE_H

#include <vector>
#include <memory>
#include "FarmUnit.h"
#include "Truck.h"

class FarmComposite : public FarmUnit {
private:
    std::vector<FarmUnit*> units; ///< Vector to store child FarmUnits

public:
    // Constructor
    FarmComposite(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState);

    // Methods
    int getTotalCapacity() override;
    void add(FarmUnit* unit);
    void remove(FarmUnit* unit);
    FarmUnit* getChild(int index);
    void buyTruck(Truck* truck);
    void sellTruck(int truckId);
    void callTruck(int truckId, const std::string& operation);
    void notifyTrucks();
};

#endif // FARMCOMPOSITE_H

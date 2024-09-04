#ifndef FARM_DECORATOR_H
#define FARM_DECORATOR_H

#include "FarmUnit.h"
#include "SoilState.h"

class FarmDecorator : public FarmUnit {
protected:
    FarmUnit* wrapee;  // The farm unit being decorated

public:
    // Constructor that takes a FarmUnit pointer to wrap
    FarmDecorator(FarmUnit* farmUnit) : wrapee(farmUnit) {}

    // Virtual destructor
    virtual ~FarmDecorator() {
        delete wrapee;  // Ensure wrapped object is properly deleted
    }

    // Override the method to get the total capacity
    virtual int getTotalCapacity() = 0;

    // Override the method to get the surface area
    int getSurfaceArea() override {
        return wrapee->getSurfaceArea();
    }

    // Override the method to get the soil state name
    std::string getsoilstateName(){
        return wrapee->getSoilStateName();
    }

    // Override the method to get the crop type
    Crop getCropType() override {
        return wrapee->getCropType();
    }

    // Override the method to print the farm's details
    void printFarm() override {
        wrapee->printFarm();
    }

    // Method to calculate the leftover capacity after some storage has been used
    virtual int getLeftoverCapacity() = 0;
    // Derived classes will override this to implement specific production increases
    virtual void increaseProduction() = 0;

    // Derived classes will override this to implement specific harvesting logic
    virtual void harvest() = 0;
};

#endif // FARM_DECORATOR_H

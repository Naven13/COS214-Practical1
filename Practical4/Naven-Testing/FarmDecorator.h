#ifndef FARM_DECORATOR_H
#define FARM_DECORATOR_H

#include "FarmUnit.h"
#include "SoilState.h"

class FarmDecorator : public FarmUnit {
protected:
    FarmUnit* wrapee;

public:
    FarmDecorator(FarmUnit* farmUnit) : wrapee(farmUnit) {}

    virtual ~FarmDecorator() {
        delete wrapee;
    }

    virtual int getTotalCapacity() = 0;

    int getSurfaceArea() override {
        return wrapee->getSurfaceArea();
    }

    std::string getsoilstateName(){
        return wrapee->getSoilStateName();
    }

    Crop getCropType() override {
        return wrapee->getCropType();
    }

    void printFarm() override {
        wrapee->printFarm();
    }

    virtual void increaseProduction() = 0;

    virtual void harvest() = 0;
};

#endif // FARM_DECORATOR_H

#ifndef FARMDECORATOR_H
#define FARMDECORATOR_H

#include "FarmUnit.h"
#include "SoilState.h"

class FarmDecorator : public FarmUnit {
public:
    FarmDecorator(FarmUnit& wrapee) :  FarmUnit(wrapee.getTotalcapacity(),wrapee.getSurfaceArea(),wrapee.getCropType().crop),wrapee(&wrapee) {}

    void printFarm() {
        this->wrapee->printFarm();
    };

    //decorator method
    virtual void applyEnhancement() = 0;

    ~FarmDecorator() override {
        delete wrapee;
    };

private:
    FarmUnit* wrapee;
};



#endif //FARMDECORATOR_H

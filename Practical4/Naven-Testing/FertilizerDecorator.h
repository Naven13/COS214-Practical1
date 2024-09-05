// FertilizerDecorator.h
#ifndef FERTILIZERDECORATOR_H
#define FERTILIZERDECORATOR_H

#include "FarmDecorator.h"

class FertilizerDecorator : public FarmDecorator {
private:
    int yieldMultiplier;

public:
    // Constructor
    FertilizerDecorator(FarmUnit* farmUnit) : FarmDecorator(farmUnit), yieldMultiplier(1) {}

    void increaseProduction() override;

    int harvest();
};

#endif // FERTILIZERDECORATOR_H

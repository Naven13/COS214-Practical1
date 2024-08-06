#ifndef SHIELDBEARER_H
#define SHIELDBEARER_H

#include "Soldiers.h"

class ShieldBearer : public Soldiers{
public:
    ShieldBearer();
    ~ShieldBearer() override;

    Soldiers* clonis() const override{
        return new ShieldBearer(*this);
    }

    ShieldBearer(const ShieldBearer &other) : Soldiers(other){
        healthPerSoldier = other.healthPerSoldier;
        damagePerSoldier = other.damagePerSoldier;
        defencePerSoldier = other.defencePerSoldier;
        amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
        unitName = other.unitName;
    }

    
};



#endif //SHIELDBEARER_H

#ifndef INFANTRY_H
#define INFANTRY_H

#include "Soldiers.h"

class Infantry : public Soldiers{
public:
    Infantry();
    ~Infantry() override;

    ConcreteMemento * militusMemento() override;

    Soldiers* clonis() const override{
         return new Infantry(*this);
    }

    Infantry(const Infantry& other) : Soldiers(other){
        healthPerSoldier = other.healthPerSoldier;
        damagePerSoldier = other.damagePerSoldier;
        defencePerSoldier = other.defencePerSoldier;
        amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
        unitName = other.unitName;
    }

    
};



#endif //INFANTRY_H

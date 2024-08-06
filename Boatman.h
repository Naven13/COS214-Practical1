#ifndef BOATMAN_H
#define BOATMAN_H

#include "Soldiers.h"

class Boatman : public Soldiers{
public:
    Boatman();
    ~Boatman() override;

    void vivificaMemento(ConcreteMemento &mem) override;

    ConcreteMemento * militusMemento() override;

    Soldiers* clonis() const override{
        return new Boatman(*this);
    }

    Boatman(const Boatman &other) : Soldiers(other){
        healthPerSoldier = other.healthPerSoldier;
        damagePerSoldier = other.damagePerSoldier;
        defencePerSoldier = other.defencePerSoldier;
        amountOfSoldiersPerUnit = other.amountOfSoldiersPerUnit;
        unitName = other.unitName;
    }

    

    
};



#endif //BOATMAN_H

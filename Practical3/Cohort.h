#ifndef COHORT_H
#define COHORT_H

#include "CompositeUnit.h"

class Cohort : public CompositeUnit{

public:
    Cohort(const Cohort& other);

    void move(Direction direction) override;

    void fight(Direction direction) override;

    int getStrength() override;

    int getAttackPower() override;

    bool add(UnitComponent *component) override;

    bool remove(UnitComponent *component) override;

    std::vector<UnitComponent *> getUnits() override;

    ~Cohort() override;
};



#endif //COHORT_H

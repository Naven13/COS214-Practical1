#ifndef UNITCOMPONENT_H
#define UNITCOMPONENT_H
#include "Direction.h"

class UnitComponent {
public:
    virtual void move(Direction direction) = 0;
    virtual void fight(Direction direction) = 0;
    virtual int getStrength()=0;
    virtual int getAttackPower()=0;
    virtual ~UnitComponent() = default;

};

#endif //UNITCOMPONENT_H

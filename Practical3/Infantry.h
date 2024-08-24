#ifndef INFANTRY_H
#define INFANTRY_H

#include <utility>

#include "UnitComponent.h"

class Infantry : public UnitComponent{
public:
    Infantry() : UnitComponent(10,10,100,1,0,0){}

    Infantry(const int defence, const int damage, const int health, const int x, const int y) :UnitComponent(defence,damage,health,1,x,y){}

    Infantry(const Infantry &other) : UnitComponent(other.defence,other.damage,other.health,1,other.x,other.y){}

    Infantry & operator=(const Infantry &other);

    bool operator<(const Infantry& other) const;

    void move(Direction direction) =0;

    void fight(Direction direction) =0;

    virtual ~Infantry() ;

    UnitComponent* clone() =0;

    void applyDamage(int damage) override;

    void die() override;

    bool operator==(UnitComponent &other) override;
};



#endif //INFANTRY_H

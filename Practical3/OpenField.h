#ifndef OPENFIELD_H
#define OPENFIELD_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class OpenFieldInfantry : public Infantry{
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~OpenFieldInfantry();

    UnitComponent * clone() override;
};

class OpenFieldCavalry : public Cavalry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~OpenFieldCavalry();

    UnitComponent* clone() override;


};


class OpenFieldArtillery : public Artillery {
public:
    void move(Direction direction) override;
    void fight(Direction direction) override;

    ~OpenFieldArtillery() ;

    UnitComponent* clone() override;


};



#endif //OPENFIELD_H

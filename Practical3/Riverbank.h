#ifndef RIVERBANK_H
#define RIVERBANK_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class RiverbankInfantry : public Infantry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    ~RiverbankInfantry() = default;

    UnitComponent * clone() override;
};

class RiverbankCavalry : public Cavalry, public UnitComponent{
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool operator==(UnitComponent &other) override;

    UnitComponent * clone() override;

    void applyDamage(int damage) override;

    void die() override;
};

class RiverbankArtillery : public Artillery, public UnitComponent {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool operator==(UnitComponent &other) override;

    UnitComponent * clone() override;

    void applyDamage(int damage) override;

    void die() override;
};



#endif //RIVERBANK_H

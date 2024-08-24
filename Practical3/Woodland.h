#ifndef WOODLANDS_H
#define WOODLANDS_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class WoodlandInfantry : public Infantry {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    Terrain getEnviroment() const override;

    ~WoodlandInfantry() = default;

    UnitComponent * clone() override;
};

class WoodlandCavalry : public Cavalry, public UnitComponent {
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool operator==(UnitComponent &other) override;

    UnitComponent * clone() override;

    void applyDamage(int damage) override;

    void die() override;
};

class WoodlandArtillery : public Artillery, public UnitComponent{
public:
    void move(Direction direction) override;

    void fight(Direction direction) override;

    bool operator==(UnitComponent &other) override;

    UnitComponent * clone() override;

    void applyDamage(int damage) override;

    void die() override;
};

#endif //WOODLANDS_H

#include "Woodland.h"
void WoodlandInfantry::move(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
    std::cout << "Infantry moves through the woodlands "<< direction << std::endl;
}

void WoodlandInfantry::fight(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
    std::cout << "Infantry attacks from the woodlands " << direction << std::endl;
}

UnitComponent * WoodlandInfantry::clone() {
    return new WoodlandInfantry(*this);
}

void WoodlandCavalry::move(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
     std::cout << "Cavalry moves through the woodlands "<< direction << std::endl;
}

void WoodlandCavalry::fight(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
    std::cout << "Cavalry attacks from the woodlands " << direction << std::endl;
}

void WoodlandArtillery::move(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
    std::cout << "Artillery moves through the woodlands "<< direction << std::endl;
}

void WoodlandArtillery::fight(Direction direction) {
    switch (direction) {
        case Direction::North:
            ++y;
            break;
        case Direction::South:
            --y;
            break;
        case Direction::East:
            ++x;
            break;
        case Direction::West:
            --x;
            break;
        default:
            x = x;
            break;
    }
    std::cout << "Artillery attacks from the woodlands " << direction << std::endl;
}

Terrain WoodlandInfantry::getEnviroment() const {
    return Infantry::getEnviroment();
}

bool WoodlandCavalry::operator==(UnitComponent &other) {
}

UnitComponent * WoodlandCavalry::clone() {
    return new WoodlandCavalry(*this);
}

void WoodlandCavalry::applyDamage(int damage) {
    Cavalry::applyDamage(damage);
}

void WoodlandCavalry::die() {
    Cavalry::die();
}

bool WoodlandArtillery::operator==(UnitComponent &other) {
}

UnitComponent * WoodlandArtillery::clone() {
    return new WoodlandArtillery(*this);
}

void WoodlandArtillery::applyDamage(int damage) {
    Artillery::applyDamage(damage);
}

void WoodlandArtillery::die() {
    Artillery::die();
}

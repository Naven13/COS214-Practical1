#include "Riverbank.h"

void RiverbankInfantry::move(Direction direction) {
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
    std::cout << "Infantry moves through the riverbank "<< direction << std::endl;
}

void RiverbankInfantry::fight(Direction direction) {
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
    std::cout << "Infantry attacks from the riverbank " << direction << std::endl;
}

UnitComponent * RiverbankInfantry::clone() {
    return new RiverbankInfantry(*this);
}

void RiverbankCavalry::move(Direction direction) {
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
    std::cout << "Cavalry moves through the riverbank "<< direction << std::endl;
}

void RiverbankCavalry::fight(Direction direction) {
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
    std::cout << "Cavalry attacks from the riverbank " << direction << std::endl;
}

void RiverbankArtillery::move(Direction direction) {
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
    std::cout << "Artillery moves through the riverbank "<< direction << std::endl;
}

void RiverbankArtillery::fight(Direction direction) {
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
    std::cout << "Artillery attacks from the riverbank " << direction << std::endl;
}

bool RiverbankCavalry::operator==(UnitComponent &other) {
    Cavalry::operator==(other);
}

UnitComponent * RiverbankCavalry::clone() {
    return new RiverbankCavalry(*this);
}

void RiverbankCavalry::applyDamage(int damage) {
    Cavalry::applyDamage(damage);
}

void RiverbankCavalry::die() {
    Cavalry::die();
}

bool RiverbankArtillery::operator==(UnitComponent &other) {
    Artillery::operator==(other);
}

UnitComponent * RiverbankArtillery::clone() {
    return new RiverbankArtillery(*this);
}

void RiverbankArtillery::applyDamage(int damage) {
    Artillery::applyDamage(damage);
}

void RiverbankArtillery::die() {
    Artillery::die();
}

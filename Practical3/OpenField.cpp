#include "OpenField.h"

void OpenFieldInfantry::move(Direction direction) override {
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
    std::cout << "Infantry moves through the fields "<< direction << std::endl;
}

void OpenFieldInfantry::fight(Direction direction) override {
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
    std::cout << "Infantry attacks from the fields " << direction << std::endl;
}

UnitComponent * OpenFieldInfantry::clone() {
    return new OpenFieldInfantry(*this);
}

void OpenFieldCavalry::move(Direction direction) override {
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
    std::cout << "Cavalry moves through the fields "<< direction << std::endl;
}

void OpenFieldCavalry::fight(Direction direction) override {
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
    std::cout << "Cavalry attacks from the fields " << direction << std::endl;
}


void OpenFieldArtillery::move(Direction direction) {
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
    std::cout << "Artillery moves through the fields "<< direction << std::endl;
}

void OpenFieldArtillery::fight(Direction direction) {
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
    std::cout << "Artillery attacks from the fields " << direction << std::endl;
}

UnitComponent * OpenFieldCavalry::clone() {
    return new OpenFieldCavalry(*this);
}

UnitComponent * OpenFieldArtillery::clone() {
    return new OpenFieldArtillery(*this);
}

OpenFieldInfantry::~OpenFieldInfantry() = default;

OpenFieldCavalry::~OpenFieldCavalry() = default;

bool OpenFieldCavalry::operator==(UnitComponent &other) {
    Cavalry::operator==(other);
}

void OpenFieldCavalry::applyDamage(int damage) {
    Cavalry::applyDamage(damage);
}

void OpenFieldCavalry::die() {
    Cavalry::die();
}

OpenFieldArtillery::~OpenFieldArtillery() = default;

bool OpenFieldArtillery::operator==(UnitComponent &other) {
    Artillery::operator==(other);
}

void OpenFieldArtillery::applyDamage(int damage) {
    Artillery::applyDamage(damage);
}

void OpenFieldArtillery::die() {
    Artillery::die();
}

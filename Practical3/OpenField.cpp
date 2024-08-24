#include "OpenField.h"

void OpenFieldInfantry::move(Direction direction) override {
    Infantry::move(direction);
    std::cout << "Infantry moves through the fields "<< direction << std::endl;
}

void OpenFieldInfantry::fight(Direction direction) override {
    Infantry::fight(direction);
    std::cout << "Infantry attacks from the fields " << direction << std::endl;
}

UnitComponent * OpenFieldInfantry::clone() {
    return new OpenFieldInfantry(*this);
}

void OpenFieldCavalry::move(Direction direction) override {
    Cavalry::move(direction);
    std::cout << "Cavalry moves through the fields "<< direction << std::endl;
}

void OpenFieldCavalry::fight(Direction direction) override {
    Cavalry::fight(direction);
    std::cout << "Cavalry attacks from the fields " << direction << std::endl;
}


void OpenFieldArtillery::move(Direction direction) {
     Artillery::move(direction);
    std::cout << "Artillery moves through the fields "<< direction << std::endl;
}

void OpenFieldArtillery::fight(Direction direction) {
    Artillery::fight(direction);
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

OpenFieldArtillery::~OpenFieldArtillery() = default;


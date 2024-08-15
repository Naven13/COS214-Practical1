#include "Legion.h"

#include "Cohort.h"

Legion::Legion(const Legion &other) {
    for (const auto &ptr: other.units) {
        this->units.push_back(ptr);
    }
    this->unitName = other.unitName;
}

Legion &Legion::operator=(const Legion &other) {
    if (this == &other) {
        return *this;
    }
    this->unitName = other.unitName;
    for (const auto &ptr: other.units) {
        this->units.push_back(ptr);
    }
    return *this;
}

bool Legion::operator<(const Legion &other) const {
    if (getStrength() < other.getStrength()) {
        return true;
    }
    return false;
}

bool Legion::operator==(const Legion &other) const {
    if (getStrength() == other.getStrength()) {
        return true;
    }
    return false;
}

void Legion::move(const Direction direction) {
    /*switch(direction) {
        case Direction::North:
            std::cout << (this->unitName) << " moving North" << std::endl;
        case Direction::East:
            std::cout << (this->unitName) << " moving East" << std::endl;
        case Direction::South:
            std::cout << (this->unitName) << " moving South" << std::endl;
         case Direction::West:
            std::cout << (this->unitName) << " moving West" << std::endl;
    }
    */

    for (UnitComponent *component: units) {
        component->move(direction);
    }
}

void Legion::fight(const Direction direction) {
    for (UnitComponent *component: units) {
        component->move(direction);
    }
}

bool Legion::add(UnitComponent *component) {
    bool success = false;
    units.push_back(component);
    return true;
}

bool Legion::remove(UnitComponent *component) {
}

bool Legion::isInUnit(UnitComponent *component) {
    if (units.size() != 0) {
        for (int i = 0; i < units.size(); i++) {
            if (units[i] == component) return true;
        }
    }
    return false;
}

int Legion::getStrength() const {
    int totalStrength = 0;
    for (UnitComponent *unit: units) {
        totalStrength += unit->getStrength();
    }
    return totalStrength;
}

int Legion::getDefence() const {
    int totalDefence = 0;
    for (UnitComponent *unit: units) {
        totalDefence += unit->getDefence();
    }
    return totalDefence;
}

std::vector<UnitComponent *>& Legion::getUnits() {
    return units;
}

Legion::~Legion() {
    for (UnitComponent *comp: units) {
        delete comp;
    }
    units.clear();
}

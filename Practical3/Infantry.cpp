#include "Infantry.h"

Infantry &Infantry::operator=(const Infantry &other) {
    this->damage = other.getDamage();
    this->defence = other.getDefence();
    this->health = other.getHealth();
    this->size = other.getSize();
    this->x = other.getX();
    this->y = other.getY();
    return *this;
}

bool Infantry::operator<(const Infantry &other) const {
    return this->getSize() < other.getSize();
}

bool Infantry::operator==(const Infantry &other) const{
    return this->getSize() == other.getSize();
}

void Infantry::move(Direction direction) {
    
    std::cout << "Infantry moves in direction " << direction << std::endl;

}

void Infantry::fight(Direction direction) {
    
    std::cout << "Infantry fights in direction " << direction << std::endl;

}

Infantry::~Infantry() = default;

std::shared_ptr<UnitComponent> Infantry::clone() {
    return std::make_shared<Infantry>(*this);
}

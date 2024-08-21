#include "Fortification.h"

void Fortification::engage(std::shared_ptr<UnitComponent> &unit) {
    if(unit->getSize() < this->minimumTroops){
        //kill all troops
        return;
    }
    
}

Fortification::~Fortification() {
}

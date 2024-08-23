//(Concrete Factory Class)
#ifndef WOODLANDFACTORY_H
#define WOODLANDFACTORY_H

#include "LegionFactory.h"
#include "Woodland.h" // Includes all the Woodland units

class WoodlandFactory : public LegionFactory {
public:
    Infantry* createInfantry() override {
        return new WoodlandInfantry();
    }
    
    Cavalry* createCavalry() override {
        return new WoodlandCavalry();
    }
    
    Artillery* createArtillery() override {
        return new WoodlandArtillery();
    }
};

#endif // WOODLANDFACTORY_H
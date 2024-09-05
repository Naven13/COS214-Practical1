#ifndef STORAGE_DECORATOR_H
#define STORAGE_DECORATOR_H

#include "FarmDecorator.h"

class StorageDecorator : public FarmDecorator {
private:
    int extraBarnCapacity;

protected:
    void addExtraBarn() {
        std::cout << "Adding extra barn to increase storage capacity by " << extraBarnCapacity << " units." << std::endl;
    }

    int getLeftoverCapacity() {
        int totalCapacity = wrapee->getTotalcapacity();
        int currentStorage = wrapee->getCurrentStorageCapacity();
        return totalCapacity - currentStorage;
    }

public:
    StorageDecorator(FarmUnit* farmUnit, int extraCapacity)
        : FarmDecorator(farmUnit), extraBarnCapacity(extraCapacity) {}

    ~StorageDecorator() override {}

    int getTotalCapacity() override {
        return wrapee->getTotalcapacity() + extraBarnCapacity;
    }

};

#endif // STORAGE_DECORATOR_H

#ifndef STORAGE_DECORATOR_H
#define STORAGE_DECORATOR_H

#include "FarmDecorator.h"

class StorageDecorator : public FarmDecorator {
private:
    int extraBarnCapacity; // The extra capacity added by each additional barn

public:
    // Constructor
    StorageDecorator(FarmUnit* farmUnit, int extraCapacity)
        : FarmDecorator(farmUnit), extraBarnCapacity(extraCapacity) {}

    // Destructor
    ~StorageDecorator() override {}

    // Override the applyEnhancement method to add storage functionality
    // void applyEnhancement() override {
    //     addExtraBarn();  // Add extra capacity by adding a barn
    //     wrapee->applyEnhancement();  // Call the wrapped object's applyEnhancement method
    // }

    // Implementation of the specific behavior for adding extra storage capacity
    void addExtraBarn() {
        // Logic to increase storage capacity
        std::cout << "Adding extra barn to increase storage capacity by " << extraBarnCapacity << " units." << std::endl;
    }

    // Override method to get the total capacity
    int getTotalCapacity() override {
        return wrapee->getTotalcapacity() + extraBarnCapacity; // Original capacity + extra barn capacity
    }

    // Method to get leftover capacity after adding storage
    int getLeftoverCapacity(){
        int totalCapacity = wrapee->getTotalcapacity();   // Total capacity of the farm
        int currentStorage = wrapee->getCurrentStorageCapacity();  // Current used capacity
        return totalCapacity - currentStorage;
    }

    // Implementation of harvest behavior, if needed
    void harvest() override {
        // Logic for harvesting with additional storage
        std::cout << "Harvesting crops with extra storage available." << std::endl;



    }

protected:
    // Implementation of increasing production
    void increaseProduction() override {
        // Example logic to increase production
        std::cout << "Increasing production due to added storage." << std::endl;

        

    }
};

#endif // STORAGE_DECORATOR_H

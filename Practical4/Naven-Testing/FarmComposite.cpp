#include "FarmComposite.h"
#include <algorithm> // For std::remove

// Constructor implementation
FarmComposite::FarmComposite(int totalCapacity, int surfaceArea, CropType cropType, SoilState &soilState)
    : FarmUnit(totalCapacity, surfaceArea, cropType, soilState) {}

// Get total capacity of the composite farm by summing the capacities of all units
int FarmComposite::getTotalCapacity() {
    int total = 0;
    for (auto* unit : units) {
        total += unit->getTotalCapacity();
    }
    return total;
}

// Add a FarmUnit to the composite
void FarmComposite::add(FarmUnit* unit) {
    units.push_back(unit);
}

// Remove a FarmUnit from the composite
void FarmComposite::remove(FarmUnit* unit) {
    units.erase(std::remove(units.begin(), units.end(), unit), units.end());
}

// Get a child FarmUnit by index
FarmUnit* FarmComposite::getChild(int index) {
    if (index >= 0 && index < units.size()) {
        return units[index];
    }
    return nullptr;
}

// Simulate purchasing a truck for the FarmComposite
void FarmComposite::buyTruck(Truck* truck) {
    // Logic to purchase and manage trucks could be implemented here.
    // Example: Add the truck to a truck management system or a vector.
}

// Simulate selling a truck from the FarmComposite
void FarmComposite::sellTruck(int truckId) {
    // Logic to sell a truck by ID could be implemented here.
    // Example: Remove the truck from the truck management system or a vector.
}

// Notify and dispatch a truck for a specific operation
void FarmComposite::callTruck(int truckId, const std::string& operation) {
    // Logic to find the truck by ID and perform the operation.
    // Example: Notify the truck to start its operation based on the truckId and operation.
}

// Notify all trucks for various operations within the FarmComposite
void FarmComposite::notifyTrucks() {
    // Logic to notify all trucks in the composite.
    // Example: Iterate through trucks and trigger operations.
}

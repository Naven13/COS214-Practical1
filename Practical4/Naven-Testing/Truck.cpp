#include "Truck.h"

// Constructor implementation
Truck::Truck(int id, float capacity) : id(id), capacity(capacity), isRunning(false) {}

// Return the truck's ID
int Truck::getId() const {
    return id;
}

// Return the truck's capacity
float Truck::getCapacity() const {
    return capacity;
}

// Check if the truck's engine is running
bool Truck::isTruckRunning() const {
    return isRunning;
}

// Start the truck's engine
void Truck::startEngine() {
    if (!isRunning) {
        isRunning = true;
        std::cout << "Truck with ID " << id << " engine started." << std::endl;
    } else {
        std::cerr << "Truck with ID " << id << " engine is already running." << std::endl;
    }
}

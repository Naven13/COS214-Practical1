#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "FarmComposite.h" // Forward declaration to avoid circular dependency

class Truck {
protected:
    int id;          ///< Unique identifier for the truck
    float capacity;  ///< Capacity of the truck
    bool isRunning;  ///< Indicates whether the truck's engine is running

public:
    // Constructor
    Truck(int id, float capacity);

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Truck() {}

    // Common truck methods
    int getId() const;
    float getCapacity() const;
    bool isTruckRunning() const;

    // Start the truck's engine
    void startEngine();

    // Pure virtual function to perform an operation, to be implemented by derived classes
    virtual void performOperation(FarmComposite* farmComposite) = 0;
};

#endif // TRUCK_H

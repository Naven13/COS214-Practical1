#ifndef TACTICALMEMENTO_H
#define TACTICALMEMENTO_H

#include "BattleStrategy.h"

class TacticalMemento {
private:
    BattleStrategy* storedStrategy;

public:
    // Default constructor
    TacticalMemento() : storedStrategy(nullptr) {}

    // Constructor with strategy
    TacticalMemento(BattleStrategy* strategy) : storedStrategy(strategy->clone()) {}
    ~TacticalMemento() { delete storedStrategy; }
    // Method to capture and store the current strategy
    void storeStrategy(BattleStrategy* strategy) {
        delete storedStrategy;  // Prevent memory leak
        storedStrategy = strategy->clone();
    }
    BattleStrategy* getStoredStrategy() const { return storedStrategy; }
};



#endif //TACTICALMEMENTO_H

#ifndef TACTICALMEMENTO_H
#define TACTICALMEMENTO_H

#include "BattleStrategy.h"
#include "TacticalPlanner.h"

class TacticalMemento {
private:

    BattleStrategy* storedStrategy;

public:
    TacticalMemento(BattleStrategy& strategy)  {
        this->storedStrategy = &strategy;
    }

    ~TacticalMemento() {
        std::cout << "Destroying memento" << std::endl;
    }

    // Method to capture and store the current strategy
    void storeStrategy(BattleStrategy& strategy) {
        storedStrategy = &strategy;
    }

    BattleStrategy* getStoredStrategy() const { return storedStrategy; }


};



#endif //TACTICALMEMENTO_H

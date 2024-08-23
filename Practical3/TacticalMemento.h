#ifndef TACTICAL_MEMENTO_H
#define TACTICAL_MEMENTO_H

#include "BattleStrategy.h"

class TacticalMemento {
private:
    BattleStrategy* storedStrategy;

public:
    TacticalMemento(BattleStrategy* strategy) : storedStrategy(strategy->clone()) {}
    ~TacticalMemento() { delete storedStrategy; }

    BattleStrategy* getStoredStrategy() const { return storedStrategy; }
};

#endif // TACTICAL_MEMENTO_H

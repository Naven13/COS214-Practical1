#ifndef TACTICALPLANNER_H
#define TACTICALPLANNER_H

#include "TacticalMemento.h"
#include "BattleStrategy.h"

class TacticalPlanner {
private:
    BattleStrategy* currentStrategy;

public:
    TacticalPlanner(BattleStrategy* strategy) : currentStrategy(strategy) {}
    void setStrategy(BattleStrategy& strategy){this->currentStrategy = &strategy;}
    ~TacticalPlanner() { delete currentStrategy; }

    TacticalMemento* createMemento() const;
    void restoreMemento(TacticalMemento* memento);
};


#endif //TACTICALPLANNER_H

#ifndef TACTICALPLANNER_H
#define TACTICALPLANNER_H

#include "TacticalMemento.h"
class TacticalMemento;

#include "BattleStrategy.h"

class TacticalPlanner {
private:
    BattleStrategy* currentStrategy;

public:
    TacticalPlanner(BattleStrategy& strategy) {
        this->currentStrategy = &strategy;
    }

    ~TacticalPlanner() {
        std::cout << "Destroying planner" << std::endl;
    }

    void setStrategy(BattleStrategy& strategy){this->currentStrategy = &strategy;}

    TacticalMemento* createMemento() const;

    void restoreMemento(TacticalMemento& memento);

    BattleStrategy* getStrategy()const{return this->currentStrategy;}
};


#endif //TACTICALPLANNER_H

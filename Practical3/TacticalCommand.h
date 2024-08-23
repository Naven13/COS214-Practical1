#ifndef TACTICALCOMMAND_H
#define TACTICALCOMMAND_H

#include "BattleStrategy.h"
#include "WarArchives.h"
#include "TacticalPlanner.h"
#include <memory>

class TacticalCommand {
private:
    BattleStrategy* strategy;
    TacticalPlanner* planner;
    WarArchives* archives;

public:
    TacticalCommand(BattleStrategy& strategy, WarArchives* archives);
    ~TacticalCommand();

    void setStrategy(BattleStrategy* strategy);
    void chooseBestStrategy();
    void executeStrategy(std::shared_ptr<UnitComponent>& unit);
};

#endif // TACTICALCOMMAND_H

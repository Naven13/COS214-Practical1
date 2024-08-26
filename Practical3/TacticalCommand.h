#ifndef TACTICALCOMMAND_H
#define TACTICALCOMMAND_H

#include "BattleStrategy.h"
#include "TacticalPlanner.h"
#include "WarArchives.h"

class TacticalCommand {
    BattleStrategy* strategy;
    TacticalPlanner* planner;
    WarArchives* archives;
public:
    void setStrategy(BattleStrategy& strategy);
    void chooseBestStrategy();
    UnitComponent* executeStrategy(std::string& strategyName);
    /*TacticalCommand(BattleStrategy& strategy);*/
    TacticalCommand(BattleStrategy& strategy, WarArchives& archives);
    ~TacticalCommand();
};

#endif //TACTICALCOMMAND_H

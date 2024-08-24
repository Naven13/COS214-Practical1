#include "TacticalCommand.h"

void TacticalCommand::setStrategy(BattleStrategy *strategy) {
    if(strategy!=nullptr) {
        //delete old stategy
        delete strategy;
        this->strategy = strategy;
    }
    this->planner->restoreMemento(new TacticalMemento(strategy));
}

void TacticalCommand::chooseBestStrategy() {

}

void TacticalCommand::executeStrategy(UnitComponent& unit,UnitComponent& enemy) {
    this->strategy->engage(unit,enemy);
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy) {
    this->strategy = &strategy;
    this->planner = new TacticalPlanner(&strategy); 
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy, WarArchives *archives) {
    this->strategy = &strategy;
    this->planner = new TacticalPlanner(&strategy);  // Initialize planner
    this->archives = archives;
}

TacticalCommand::~TacticalCommand() {
    delete planner;
    delete strategy;
}

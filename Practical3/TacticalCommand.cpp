#include "TacticalCommand.h"

void TacticalCommand::setStrategy(BattleStrategy& strategy) {
    if(this->strategy!=nullptr) {
        //delete old stategy
        delete this->strategy;
        this->strategy = &strategy;
    }
    this->planner->setStrategy(strategy);
}

void TacticalCommand::chooseBestStrategy() {
    this->archives->restoreBestMemento(*planner);
    delete this->strategy;
    this->strategy = planner->getStrategy();
}

UnitComponent* TacticalCommand::executeStrategy(std::string& strategyName) {

    archives->addTacticalMemento(*this->planner->createMemento(),strategyName);
    return this->strategy->engage();
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy, WarArchives &archives) {
    this->strategy = &strategy;
    this->archives = &archives;
    this->planner = new TacticalPlanner(strategy);
}

TacticalCommand::~TacticalCommand() {
    delete planner;
    delete strategy;
    delete archives;
}

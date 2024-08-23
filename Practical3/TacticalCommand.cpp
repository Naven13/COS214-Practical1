#include "TacticalCommand.h"

TacticalCommand::TacticalCommand(BattleStrategy& strategy, WarArchives* archives) {
    this->strategy = &strategy;
    this->archives = archives;
    this->planner = new TacticalPlanner(this->strategy);
}

TacticalCommand::~TacticalCommand() {
    delete planner;
    delete strategy;
}

void TacticalCommand::setStrategy(BattleStrategy* strategy) {
    if (this->strategy != nullptr) {
        delete this->strategy;
    }
    this->strategy = strategy;
    this->planner->restoreMemento(new TacticalMemento(strategy));
}

void TacticalCommand::chooseBestStrategy() {
    // Example logic: Choose the first strategy in the archives
    TacticalMemento* bestMemento = archives->getMemento("bestStrategy");
    if (bestMemento != nullptr) {
        setStrategy(bestMemento->getStoredStrategy()->clone());
    }
}

void TacticalCommand::executeStrategy(std::shared_ptr<UnitComponent>& unit) {
    if (strategy) {
        strategy->engage(unit);
    }
}

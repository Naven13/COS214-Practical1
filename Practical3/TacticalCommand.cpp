#include "TacticalCommand.h"

void TacticalCommand::setStrategy(TacticalMemento &memento) {
    if(this->strategy!=nullptr) {
        //delete old stategy
        delete this->strategy;
        this->strategy = memento.getStoredStrategy();
    }
    this->planner->restoreMemento(&memento);
}

void TacticalCommand::chooseBestStrategy() {
    this->setStrategy(*archives->returnBestMemento());
}

void TacticalCommand::executeStrategy(std::string& strategyName) {
    this->strategy->engage();
    archives->addTacticalMemento(this->planner->createMemento(),strategyName);
}

TacticalCommand::TacticalCommand(BattleStrategy &strategy, WarArchives &archives) {
    this->strategy = &strategy;
    this->archives = &archives;
    this->planner = new TacticalPlanner(&strategy);
}

TacticalCommand::~TacticalCommand() {
    delete planner;
    delete strategy;
    delete archives;
}

#include "WarArchives.h"
WarArchives::~WarArchives() {
    for (auto& pair : mementoMap) {
        delete pair.second;
    }
    mementoMap.clear();
    std::cout << "Destroy war archives" << std::endl;
}

void WarArchives::addTacticalMemento(TacticalMemento& memento, const std::string& label) {

    if (mementoMap.find(label) != mementoMap.end()) {
        delete mementoMap[label]; // Clean up existing
    }

    mementoMap[label] = &memento;

}

void WarArchives::removeTacticalMemento(const std::string& label) {
    auto it = mementoMap.find(label);
    if (it != mementoMap.end()) {
        delete it->second; // Delete the pointer
        mementoMap.erase(it);   // Erase the element from the map
    }

}

TacticalMemento& WarArchives::getMemento(const std::string& label) {
    auto it = mementoMap.find(label);
    if (it != mementoMap.end()) {
        return *it->second;
    }
    return *mementoMap.begin()->second;
}

void WarArchives::restoreBestMemento(TacticalPlanner& planner) {
    int randomIndex = std::rand() % mementoMap.size();
    auto it = mementoMap.begin();
    std::advance(it, randomIndex);

    planner.restoreMemento(*it->second);
}


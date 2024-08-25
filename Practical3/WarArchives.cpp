#include "WarArchives.h"
WarArchives::~WarArchives() {
    for (auto& pair : mementoMap) {
        delete pair.second;
    }
}

void WarArchives::addTacticalMemento(TacticalMemento* memento, const std::string& label) {
    if (mementoMap.find(label) != mementoMap.end()) {
        delete mementoMap[label]; // Clean up existing
    }
    mementoMap[label] = memento;
}

void WarArchives::removeTacticalMemento(const std::string& label) {
    delete mementoMap[label];
    mementoMap.erase(label);
}

TacticalMemento* WarArchives::getMemento(const std::string& label) {
    return mementoMap[label];
}

TacticalMemento* WarArchives::returnBestMemento() {
    int randomIndex = std::rand() % mementoMap.size();
    auto it = mementoMap.begin();
    std::advance(it, randomIndex);
    return it->second;
}
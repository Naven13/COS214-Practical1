#ifndef BATTLESTRATEGY_H
#define BATTLESTRATEGY_H

#include "UnitComponent.h"

enum class Terrain {
    Woodlands,
    Riverbank,
    OpenField
};

class BattleStrategy {
private:
    float successRate;       // success rate
    int minimumTroops;       // minimum number of troops to succeed - if less then auto fail
    int damagePotential;     // damage it can inflict if successful
    int defenceBonus;        // add defence bonus to UnitComponent
    int executionTime;       // time needed to execute the strategy (in rounds)
    Terrain bestEnvironment; // environment with the most success
    int riskLevel;           // risk level out of 10

public:
    BattleStrategy(float successRate, int minTroops, int damagePotential, int defenceBonus, int executionTime,
                   Terrain bestEnvironment, int riskLevel) 
        : successRate(successRate), minimumTroops(minTroops), damagePotential(damagePotential),
          defenceBonus(defenceBonus), executionTime(executionTime), bestEnvironment(bestEnvironment),
          riskLevel(riskLevel) {}

    virtual ~BattleStrategy() = default;

    // Pure virtual method to be implemented by derived classes
    virtual void engage(std::shared_ptr<UnitComponent>& unit) = 0;

    // Pure virtual clone method for polymorphic copying
    virtual BattleStrategy* clone() const = 0;

    // Getters and setters
    float getSuccessRate() const { return successRate; }
    int getMinimumTroops() const { return minimumTroops; }
    int getDamagePotential() const { return damagePotential; }
    int getDefenceBonus() const { return defenceBonus; }
    int getExecutionTime() const { return executionTime; }
    Terrain getBestEnvironment() const { return bestEnvironment; }
    int getRiskLevel() const { return riskLevel; }

    void setSuccessRate(float successRate) { this->successRate = successRate; }
    void setMinimumTroops(int minimumTroops) { this->minimumTroops = minimumTroops; }
    void setDamagePotential(int damagePotential) { this->damagePotential = damagePotential; }
    void setDefenceBonus(int defenceBonus) { this->defenceBonus = defenceBonus; }
    void setExecutionTime(int executionTime) { this->executionTime = executionTime; }
    void setBestEnvironment(Terrain bestEnvironment) { this->bestEnvironment = bestEnvironment; }
    void setRiskLevel(int riskLevel) { this->riskLevel = riskLevel; }
};

#endif // BATTLESTRATEGY_H

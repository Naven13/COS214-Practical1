#include <iostream>

#include "Artillery.h"
#include "Legion.h"
#include "Infantry.h"
#include "UnitComponent.h"
#include "Cavalry.h"
#include "Direction.h"
#include "UnitComponent.h"
#include "OpenFieldFactory.h"
#include "WoodlandFactory.h"
#include "RiverbankFactory.h"
#include "TacticalPlanner.h"
#include "TacticalMemento.h"
#include "TacticalCommand.h"
#include "WarArchives.h"
#include "BattleStrategy.h"  // Include the header file for BattleStrategy and its implementations
#include "Flanking.h"        // Include headers for concrete strategies
#include "Fortification.h"
#include "Ambush.h"

const std::string red = "\033[31m";
const std::string green = "\033[32m";
const std::string reset = "\033[0m";


int main() {
    std::cout << "Legion Test" << std::endl;
    int passed = 0;
    int total = 0;

    ++total;
    Legion legion1{};
    if (legion1.getDefence() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getDamage() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getHealth() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getSize() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    if (legion1.getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;

    const auto legion1_units = legion1.getUnits();
    if (legion1_units.empty()) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    legion1.fight(Direction::East);
    legion1.fight(Direction::North);
    legion1.fight(Direction::South);
    legion1.fight(Direction::West);
    legion1.move(Direction::East);
    legion1.move(Direction::North);
    legion1.move(Direction::South);
    legion1.move(Direction::West);

    if (true) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    Legion legion2;
    if (legion1 == legion2) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if ((legion1 < legion2) == false) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    auto infantry1 = new Infantry();
    legion1.add(*infantry1);
    if (legion1.getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (legion1.getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (legion2.getSize() == 0) {
        legion2 = legion1;
        if (legion2.getSize() == 1) {
            ++passed;
            std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
        }
    }

    std::cout << "Factory Tests" << std::endl;
    passed = 0;
    total = 0;

    OpenFieldFactory openFieldFactory;
    WoodlandFactory woodlandFactory;
    RiverbankFactory riverbankFactory;

    ++total;
    auto openFieldArtillery = openFieldFactory.createArtillery();
    auto woodlandArtillery = woodlandFactory.createArtillery();
    auto riverbankArtillery = riverbankFactory.createArtillery();

    if (openFieldArtillery != nullptr && woodlandArtillery != nullptr && riverbankArtillery != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    auto openFieldInfantry = openFieldFactory.createInfantry();
    auto woodlandInfantry = woodlandFactory.createInfantry();
    auto riverbankInfantry = riverbankFactory.createInfantry();

    if (openFieldInfantry != nullptr && woodlandInfantry != nullptr && riverbankInfantry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    auto openFieldCavalry = openFieldFactory.createCavalry();
    auto woodlandCavalry = woodlandFactory.createCavalry();
    auto riverbankCavalry = riverbankFactory.createCavalry();

    if (openFieldCavalry != nullptr && woodlandCavalry != nullptr && riverbankCavalry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }


    ++total;
    if (openFieldArtillery->getDefence() == 10 && woodlandArtillery->getDefence() == 10 && riverbankArtillery->
        getDefence() == 10) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldInfantry->getDefence() == 10 && woodlandInfantry->getDefence() == 10 && riverbankInfantry->getDefence()
        == 10) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldCavalry->getDefence() == 15 && woodlandCavalry->getDefence() == 15 && riverbankCavalry->getDefence() ==
        15) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldArtillery->getDamage() == 30 && woodlandArtillery->getDamage() == 30 && riverbankArtillery->getDamage()
        == 30) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldInfantry->getDamage() == 10 && woodlandInfantry->getDamage() == 10 && riverbankInfantry->getDamage() ==
        10) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldCavalry->getDamage() == 15 && woodlandCavalry->getDamage() == 15 && riverbankCavalry->getDamage() ==
        15) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldArtillery->getHealth() == 100 && woodlandArtillery->getHealth() == 100 && riverbankArtillery->
        getHealth() == 100) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldInfantry->getHealth() == 100 && woodlandInfantry->getHealth() == 100 && riverbankInfantry->getHealth()
        == 100) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldCavalry->getHealth() == 100 && woodlandCavalry->getHealth() == 100 && riverbankCavalry->getHealth() ==
        100) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldArtillery->getSize() == 1 && woodlandArtillery->getSize() == 1 && riverbankArtillery->getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldInfantry->getSize() == 1 && woodlandInfantry->getSize() == 1 && riverbankInfantry->getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldCavalry->getSize() == 1 && woodlandCavalry->getSize() == 1 && riverbankCavalry->getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldArtillery->getX() == 0 && woodlandArtillery->getX() == 0 && riverbankArtillery->getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldInfantry->getX() == 0 && woodlandInfantry->getX() == 0 && riverbankInfantry->getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldCavalry->getX() == 0 && woodlandCavalry->getX() == 0 && riverbankCavalry->getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldArtillery->getY() == 0 && woodlandArtillery->getY() == 0 && riverbankArtillery->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldInfantry->getY() == 0 && woodlandInfantry->getY() == 0 && riverbankInfantry->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (openFieldCavalry->getY() == 0 && woodlandCavalry->getY() == 0 && riverbankCavalry->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    openFieldArtillery->applyDamage(10);
    woodlandArtillery->applyDamage(20);
    riverbankArtillery->applyDamage(30);
    ++total;
    openFieldInfantry->applyDamage(10);
    woodlandInfantry->applyDamage(20);
    riverbankInfantry->applyDamage(30);
    ++total;
    openFieldCavalry->applyDamage(10);
    woodlandCavalry->applyDamage(20);
    riverbankCavalry->applyDamage(30);

    if (openFieldArtillery->getHealth() == 90 && woodlandArtillery->getHealth() == 80 && riverbankArtillery->getHealth()
        == 70) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    if (openFieldInfantry->getHealth() == 90 && woodlandInfantry->getHealth() == 80 && riverbankInfantry->getHealth() ==
        70) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    if (openFieldCavalry->getHealth() == 90 && woodlandCavalry->getHealth() == 80 && riverbankCavalry->getHealth() ==
        70) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (!(openFieldArtillery == woodlandArtillery) && !(woodlandArtillery == openFieldArtillery) && !(
            riverbankArtillery == openFieldArtillery) && !(woodlandArtillery == riverbankArtillery)) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (!(openFieldInfantry == woodlandInfantry) && !(woodlandInfantry == openFieldInfantry) && !(
            riverbankInfantry == openFieldInfantry) && !(riverbankInfantry == woodlandInfantry)) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (!(openFieldCavalry == woodlandCavalry) && !(woodlandCavalry == openFieldCavalry) && !(
            riverbankCavalry == openFieldCavalry) && !(woodlandCavalry == riverbankCavalry)) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (!(openFieldArtillery < woodlandArtillery) && !(woodlandArtillery < openFieldArtillery) && !(
            riverbankArtillery < openFieldArtillery) && !(woodlandArtillery < riverbankArtillery)) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (!(openFieldInfantry < woodlandInfantry) && !(woodlandInfantry < openFieldInfantry) && !(
            riverbankInfantry < openFieldInfantry) && !(woodlandInfantry < riverbankInfantry)) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if (!(openFieldCavalry < woodlandCavalry) && !(woodlandCavalry < openFieldCavalry) && !(
            riverbankCavalry < openFieldCavalry) && !(woodlandCavalry < riverbankCavalry)) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    openFieldArtillery->applyDamage(200);
    woodlandArtillery->applyDamage(200);
    riverbankArtillery->applyDamage(200);
    if (openFieldArtillery->getHealth() == 0 && woodlandArtillery->getHealth() == 0 && riverbankArtillery->getHealth()
        == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    openFieldInfantry->applyDamage(200);
    woodlandInfantry->applyDamage(200);
    riverbankInfantry->applyDamage(200);
    if (openFieldInfantry->getHealth() == 0 && woodlandInfantry->getHealth() == 0 && riverbankInfantry->getHealth() ==
        0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    openFieldCavalry->applyDamage(200);
    woodlandCavalry->applyDamage(200);
    riverbankCavalry->applyDamage(200);
    if (openFieldCavalry->getHealth() == 0 && woodlandCavalry->getHealth() == 0 && riverbankCavalry->getHealth() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    /*++total;
    if((openFieldArtillery==woodlandArtillery) && (woodlandArtillery==openFieldArtillery) && (riverbankArtillery==openFieldArtillery) && (woodlandArtillery==riverbankArtillery)){
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }*/

    legion1.add(*openFieldArtillery);
    legion1.add(*woodlandArtillery);
    legion1.add(*riverbankArtillery);

    legion1.add(*openFieldInfantry);
    legion1.add(*woodlandInfantry);
    legion1.add(*riverbankInfantry);

    legion1.add(*openFieldCavalry);
    legion1.add(*woodlandCavalry);
    legion1.add(*riverbankCavalry);

    //test copy constructors
    Legion legion1_copy(legion1);
    ++total;
    if (legion1_copy.getSize() == 10) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }


    legion1_copy.fight(Direction::East);
    ++total;
    if (openFieldArtillery->getX() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    legion1_copy.fight(Direction::North);
    ++total;
    if (woodlandArtillery->getY() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    legion1_copy.fight(Direction::South);
    ++total;
    if (riverbankArtillery->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    legion1_copy.fight(Direction::West);
    ++total;
    if (riverbankArtillery->getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    legion1_copy.move(Direction::East);
    ++total;
    if (legion1_copy.getX() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    Artillery artillery_constructor_test(100, 100, 100, 30, 30);
    Infantry infantry_constructor_test(100, 100, 100, 30, 30);
    Cavalry cavalry_constructor_test(100, 100, 100, 30, 30);

    Artillery artillery_clone_test(artillery_constructor_test);
    Infantry infantry_clone_test(infantry_constructor_test);
    Cavalry cavalry_clone_test(cavalry_constructor_test);

    ++total;
    if (artillery_constructor_test == artillery_clone_test && infantry_constructor_test == infantry_clone_test &&
        cavalry_constructor_test == cavalry_clone_test) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed! ;)" << reset << std::endl;
    }

    auto inf_ptr = infantry_clone_test.clone();
    auto art_ptr = artillery_clone_test.clone();
    auto cav_ptr = cavalry_clone_test.clone();

    delete inf_ptr;
    delete art_ptr;
    delete cav_ptr;

    inf_ptr = nullptr;
    art_ptr = nullptr;
    cav_ptr = nullptr;

    artillery_clone_test.move(Direction::East);
    infantry_clone_test.move(Direction::East);
    cavalry_clone_test.move(Direction::East);

    ++total;
    if (artillery_clone_test.getX() == 1 && infantry_clone_test.getX() == 1  && cavalry_clone_test.getX() == 1 ) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed! ;)" << reset << std::endl;
    }

    artillery_clone_test.fight(Direction::North);
    infantry_clone_test.fight(Direction::North);
    cavalry_clone_test.fight(Direction::North);

    ++total;
    if (artillery_clone_test.getY() == 1 && infantry_clone_test.getY() == 1  && cavalry_clone_test.getY() == 1 ) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed! ;)" << reset << std::endl;
    }

    artillery_clone_test.applyDamage(1);
    infantry_clone_test.applyDamage(1);
    cavalry_clone_test.applyDamage(1);

    ++total;
    if (artillery_clone_test.getHealth() == 99 && infantry_clone_test.getHealth() == 99  && cavalry_clone_test.getHealth() == 99 ) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed! ;)" << reset << std::endl;
    }

    artillery_clone_test.die();
    infantry_clone_test.die();
    cavalry_clone_test.die();

    ++total;
    if (artillery_clone_test.getHealth() == 0 && infantry_clone_test.getHealth() == 0  && cavalry_clone_test.getHealth() == 0 ) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed! ;)" << reset << std::endl;
    }

    /*LegionFactory* factory = new WoodlandFactory();
    WarArchives* arch = new WarArchives();
    Fortification fortStrat = new Fortification(*factory);
    TacticalCommand(new Fortification(new WoodlandFactory()),new WarArchives());*/


    return 0;
}

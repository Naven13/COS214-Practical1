#include <iostream>
#include "Artillery.h"
#include "Legion.h"
#include "Infantry.h"
#include "UnitComponent.h"
#include "OpenFieldFactory.h"
#include "OpenField.h"
#include "RiverbankFactory.h"
#include "Riverbank.h"
#include "Woodland.h"
#include "WoodlandFactory.h"

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
    const std::list<std::shared_ptr<UnitComponent>> legion1_units = legion1.getUnits();
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
    if(legion1==legion2) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if((legion1<legion2) == false) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    std::shared_ptr<UnitComponent> infantry1 = std::make_shared<Infantry>();
    legion1.add(infantry1);
    if(legion1.getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    }

    ++total;
    if(legion1.getSize() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
        //std::cout<<"Next test Failed?"<<std::endl;
    }

    ++total;
    if(legion2.getSize() == 0) {
        legion2 = legion1;
        if(legion2.getSize() == 1) {
         ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
        std::cout<<"Test Failed?"<<std::endl;
        }
        else{
        std::cout<<red<<"\t"<<"Test "<<total<<" failed!"<<reset<<std::endl;
        }
    }

    // Tests for OpenFieldFactory
    std::cout << "OpenFieldFactory Test" << std::endl;

    ++total;
    OpenFieldFactory factory{};
    Infantry* openFieldInfantry = factory.createInfantry();
    if (openFieldInfantry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    Cavalry* openFieldCavalry = factory.createCavalry();
    if (openFieldCavalry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    Artillery* openFieldArtillery = factory.createArtillery();
    if (openFieldArtillery != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for OpenFieldInfantry
    std::cout << "OpenFieldInfantry Test" << std::endl;

    ++total;
    openFieldInfantry->move(Direction::North);
    if (openFieldInfantry->getY() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    openFieldInfantry->fight(Direction::South);
    if (openFieldInfantry->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for OpenFieldCavalry
    std::cout << "OpenFieldCavalry Test" << std::endl;

    ++total;
    openFieldCavalry->move(Direction::East);
    if (openFieldCavalry->getX() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    openFieldCavalry->fight(Direction::West);
    if (openFieldCavalry->getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for OpenFieldArtillery
    std::cout << "OpenFieldArtillery Test" << std::endl;

    ++total;
    openFieldArtillery->move(Direction::North);
    if (openFieldArtillery->getY() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    openFieldArtillery->fight(Direction::South);
    if (openFieldArtillery->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Clean up
    delete openFieldInfantry;
    delete openFieldCavalry;
    delete openFieldArtillery;

    // Tests for RiverbankFactory
    std::cout << "RiverbankFactory Test" << std::endl;

    ++total;
    RiverbankFactory factory2{};
    Infantry* RiverbankInfantry = factory2.createInfantry();
    if (RiverbankInfantry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    Cavalry* RiverbankCavalry = factory2.createCavalry();
    if (RiverbankCavalry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    Artillery* RiverbankArtillery = factory2.createArtillery();
    if (RiverbankArtillery != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for RiverbankInfantry
    std::cout << "RiverbankInfantry Test" << std::endl;

    ++total;
    RiverbankInfantry->move(Direction::North);
    if (RiverbankInfantry->getY() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    RiverbankInfantry->fight(Direction::South);
    if (RiverbankInfantry->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for RiverbankCavalry
    std::cout << "RiverbankCavalry Test" << std::endl;

    ++total;
    RiverbankCavalry->move(Direction::East);
    if (RiverbankCavalry->getX() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    RiverbankCavalry->fight(Direction::West);
    if (RiverbankCavalry->getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for RiverbankArtillery
    std::cout << "RiverbankArtillery Test" << std::endl;

    ++total;
    RiverbankArtillery->move(Direction::North);
    if (RiverbankArtillery->getY() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    RiverbankArtillery->fight(Direction::South);
    if (RiverbankArtillery->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }
    // Clean up
    delete RiverbankInfantry;
    delete RiverbankCavalry;
    delete RiverbankArtillery;

    // Tests for WoodlandFactory
    std::cout << "WoodlandFactory Test" << std::endl;

    ++total;
    WoodlandFactory factory3{};
    Infantry* WoodlandInfantry = factory3.createInfantry();
    if (WoodlandInfantry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    Cavalry* WoodlandCavalry = factory3.createCavalry();
    if (WoodlandCavalry != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    Artillery* WoodlandArtillery = factory3.createArtillery();
    if (WoodlandArtillery != nullptr) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for WoodlandInfantry
    std::cout << "WoodlandInfantry Test" << std::endl;

    ++total;
    WoodlandInfantry->move(Direction::North);
    if (WoodlandInfantry->getY() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    WoodlandInfantry->fight(Direction::South);
    if (WoodlandInfantry->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for WoodlandCavalry
    std::cout << "WoodlandCavalry Test" << std::endl;

    ++total;
    WoodlandCavalry->move(Direction::East);
    if (WoodlandCavalry->getX() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    WoodlandCavalry->fight(Direction::West);
    if (WoodlandCavalry->getX() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    // Tests for WoodlandArtillery
    std::cout << "WoodlandArtillery Test" << std::endl;

    ++total;
    WoodlandArtillery->move(Direction::North);
    if (WoodlandArtillery->getY() == 1) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    ++total;
    WoodlandArtillery->fight(Direction::South);
    if (WoodlandArtillery->getY() == 0) {
        ++passed;
        std::cout << green << "\t" << "Test " << total << " passed!" << reset << std::endl;
    } else {
        std::cout << red << "\t" << "Test " << total << " failed!" << reset << std::endl;
    }

    std::cout << "Total Tests Passed: " << passed << " out of " << total << std::endl;

    // Clean up
    delete WoodlandInfantry;
    delete WoodlandCavalry;
    delete WoodlandArtillery;

    

    return 0;
}
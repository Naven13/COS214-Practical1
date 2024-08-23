#include <iostream>
#include "Legion.h"
#include "OpenFieldFactory.h"
#include "WoodlandFactory.h"
#include "RiverbankFactory.h"

int TestingMain() {
    int passed = 0;
    int total = 0;

    OpenFieldFactory openFieldFactory;
    WoodlandFactory woodlandFactory;
    RiverbankFactory riverbankFactory;

    Legion openFieldLegion;
    total++;
    auto openFieldInfantry = std::shared_ptr<UnitComponent>(openFieldFactory.createInfantry());
    auto openFieldCavalry = std::shared_ptr<UnitComponent>(openFieldFactory.createCavalry());
    auto openFieldArtillery = std::shared_ptr<UnitComponent>(openFieldFactory.createArtillery());

    openFieldLegion.add(openFieldInfantry);
    openFieldLegion.add(openFieldCavalry);
    openFieldLegion.add(openFieldArtillery);
    if (openFieldLegion.getSize() == 3) {
        passed++;
        std::cout << "Test " << total << " passed!" << std::endl;
    }

    Legion woodlandLegion;
    total++;
    auto woodlandInfantry = std::shared_ptr<UnitComponent>(woodlandFactory.createInfantry());
    auto woodlandCavalry = std::shared_ptr<UnitComponent>(woodlandFactory.createCavalry());
    auto woodlandArtillery = std::shared_ptr<UnitComponent>(woodlandFactory.createArtillery());

    woodlandLegion.add(woodlandInfantry);
    woodlandLegion.add(woodlandCavalry);
    woodlandLegion.add(woodlandArtillery);
    if (woodlandLegion.getSize() == 3) {
        passed++;
        std::cout << "Test " << total << " passed!" << std::endl;
    }

    Legion riverbankLegion;
    total++;
    auto riverbankInfantry = std::shared_ptr<UnitComponent>(riverbankFactory.createInfantry());
    auto riverbankCavalry = std::shared_ptr<UnitComponent>(riverbankFactory.createCavalry());
    auto riverbankArtillery = std::shared_ptr<UnitComponent>(riverbankFactory.createArtillery());

    riverbankLegion.add(riverbankInfantry);
    riverbankLegion.add(riverbankCavalry);
    riverbankLegion.add(riverbankArtillery);
    if (riverbankLegion.getSize() == 3) {
        passed++;
        std::cout << "Test " << total << " passed!" << std::endl;
    }

    std::cout << "Total Tests Passed: " << passed << " out of " << total << std::endl;

    return 0;
}

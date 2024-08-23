#ifndef WOODLAND_H
#define WOODLAND_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class WoodlandInfantry : public Infantry {
public:
    void move(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        std::cout << "WoodlandInfantry moves in direction " << direction << std::endl;
    }

    void fight(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        std::cout << "WoodlandInfantry fights in direction " << direction << std::endl;
    }
};

class WoodlandCavalry : public Cavalry {
public:
    void move(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        std::cout << "WoodlandCavalry moves in direction " << direction << std::endl;
    }

    void fight(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        std::cout << "WoodlandCavalry fights in direction " << direction << std::endl;
    }
};

class WoodlandArtillery : public Artillery {
public:
    void move(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        std::cout << "WoodlandArtillery moves in direction " << direction << std::endl;
    }

    void fight(Direction direction) override {
        switch (direction) {
            case Direction::North:
                ++y;
                break;
            case Direction::South:
                --y;
                break;
            case Direction::East:
                ++x;
                break;
            case Direction::West:
                --x;
                break;
            default:
                x = x;
                break;
        }
        std::cout << "WoodlandArtillery fights in direction " << direction << std::endl;
    }
};

#endif // WOODLAND_H

#ifndef OPENFIELD_H
#define OPENFIELD_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class OpenFieldInfantry : public Infantry {
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
        std::cout << "OpenFieldInfantry moves in direction " << direction << std::endl;
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
        std::cout << "OpenFieldInfantry fights in direction " << direction << std::endl;
    }
};

class OpenFieldCavalry : public Cavalry {
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
        std::cout << "OpenFieldCavalry moves in direction " << direction << std::endl;
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
        std::cout << "OpenFieldCavalry fights in direction " << direction << std::endl;
    }
};

class OpenFieldArtillery : public Artillery {
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
        std::cout << "OpenFieldCavalry moves in direction " << direction << std::endl;
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
        std::cout << "OpenFieldCavalry fights in direction " << direction << std::endl;
    }
};

#endif // OPENFIELD_H

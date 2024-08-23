#ifndef RIVERBANK_H
#define RIVERBANK_H

#include "Infantry.h"
#include "Cavalry.h"
#include "Artillery.h"

class RiverbankInfantry : public Infantry {
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
        std::cout << "RiverbankInfantry moves in direction " << direction << std::endl;
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
        std::cout << "RiverbankInfantry fights in direction " << direction << std::endl;
    }
};

class RiverbankCavalry : public Cavalry {
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
        std::cout << "RiverbankCavalry moves in direction " << direction << std::endl;
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
        std::cout << "RiverbankCavalry fights in direction " << direction << std::endl;
    }
};

class RiverbankArtillery : public Artillery {
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
        std::cout << "RiverArtillery moves in direction " << direction << std::endl;
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
        std::cout << "RiverbankArtillery fights in direction " << direction << std::endl;
    }
};

#endif // RIVERBANK_H

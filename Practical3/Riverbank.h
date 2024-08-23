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
    }
};

#endif // RIVERBANK_H

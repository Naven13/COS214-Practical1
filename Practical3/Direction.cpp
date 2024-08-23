#include "Direction.h"

std::ostream& operator<<(std::ostream& os, Direction direction) {
    switch (direction) {
        case Direction::North:
            os << "North";
            break;
        case Direction::South:
            os << "South";
            break;
        case Direction::East:
            os << "East";
            break;
        case Direction::West:
            os << "West";
            break;
        default:
            os << "Unknown Direction";
            break;
    }
    return os;
}

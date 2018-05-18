#include "Coordinate.h"

Coordinate::Coordinate(){}

Coordinate::Coordinate(const Coordinate & c){
    this->x = c.x;
    this->y = c.y;
}

Coordinate::Coordinate(uint x, uint y){
    this->x = x; // yogev ha zevel
    this->y = y;
}
#include "Coordinate.h"

Coordinate::Coordinate(){}

Coordinate::Coordinate(const Coordinate & c){
    this->x = c.x;
    this->x = c.y;
}

Coordinate::Coordinate(uint x, uint y){
    this->x = x;
    this->x = y;
}
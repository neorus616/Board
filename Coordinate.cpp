#include <Coordinate.h>

Coordinate::Coordinate(){}

Coordinate::Coordinate(const Coordinate & c){
    this->x = c.x;
    this->x = c.y;
}

Coordinate::Coordinate(int x, int y){
    this->x = x;
    this->x = y;
}
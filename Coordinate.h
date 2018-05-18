#pragma once
#include <sys/types.h>

class Coordinate{
    public:
        uint x;
        uint y;    
        Coordinate();
        Coordinate(uint, uint);
        Coordinate(const Coordinate &);
};
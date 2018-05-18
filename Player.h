#pragma once
#include <string>
#include "Board.h"

using namespace std;

class Player{
    public:
        Player();
        Player(char);
        virtual const std::string name() const;
        char myChar;
        virtual const Coordinate play(const Board& board);
        virtual const char getChar() const;
};
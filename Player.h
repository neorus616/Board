#pragma once
#include <string>
#include "Board.h"

using namespace std;

class Player{
    public:
        Player();
        virtual const string name() const;
        char myChar;
        virtual const Coordinate play(const Board&);
        virtual const char getChar() const;
        void setChar(char);
};
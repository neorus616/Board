#pragma once
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class TicTacToe{
    private:
        int size;
        Board* game;
        Player* _winner;
        bool boardFull();
        bool winMove(Coordinate,char);
        
    public:
        TicTacToe(int);
        Board& board() const;
        Player& winner() const;
        void play(Player&, Player&);
        ~TicTacToe();
    
};
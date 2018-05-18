#pragma once
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
using namespace std;

Class TicTacToe{
    private:
        int size;
        Board game;
    
    public:
    TicTacToe(int);
    Board& board();
    Player& winner();
    void play(Player&, Player&);
    
};
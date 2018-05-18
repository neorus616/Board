#include <iostream>
#include <string>
#include "TicTacToe.h"
using namespace std;


TicTacToe::TicTacToe(int size){
    this->size = size;
    game = new Board(size);
}

Board& TicTacToe::board(){
    return game;
}

Player& TicTacToe::winner(){
    return winner;
}

void TicTacToe::play(Player& first, Player& second){
    
}
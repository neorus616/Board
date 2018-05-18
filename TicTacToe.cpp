#include <iostream>
#include <string>
#include "TicTacToe.h"
using namespace std;


TicTacToe::TicTacToe(int size){
    this->size = size;
    game = new Board(size);
}

Board& TicTacToe::board() const{
    return *game;
}

Player& TicTacToe::winner() const{
    return *_winner;
}

void TicTacToe::play(Player& xPlayer, Player& oPlayer){
    
}

bool TicTacToe::boardFull(){
    for(uint i = 0 ; i < this->size ; i++){
        for(uint j = 0 ; i < this->size ; j++){
            if(board()[{i,j}] == 'X' || board()[{i,j}] == 'O')
                return false;
        }
    }
    return true;
}
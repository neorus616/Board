#include <iostream>
#include <string>
#include "Board.h"



Board::Board(int size){
    this->size = size;
    board = new char*[size];
    for(int i = 0; i < size; i++){
        board[i] = new char[size];
        for(int j = 0 ; j < size ; j++)
            board[i][j] = '.';
    }
}

ostream& operator << (ostream& os, Board const & board){
    for(int i = 0 ; i < board.size ; i++)
        for(int j = 0 ; j < board.size ; j++){
            os << board.board[i][j];
            if(j == board.size - 1 and i != board.size-1)
            os << endl;
        }
    return os;
}


Board::~Board(){}
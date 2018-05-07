#include <iostream>
#include <string>
#include "Board.h"
using namespace std;



Board::Board(int size){
    this->size = size;
    board = new char*[size];
    for(int i = 0; i < size; i++){
        board[i] = new char[size];
        for(int j = 0 ; j < size ; j++)
            board[i][j] = '.';
    }
}

char& Board::operator[](list<int> coor){
    if(coor.size() != 2)
        throw "wrong input";
	int a = coor.front();
	int b = coor.back();
		return this->board[a][b];
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
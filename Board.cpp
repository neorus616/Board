#include <iostream>
#include <string>
#include <exception>
#include "Board.h"
using namespace std;

struct IllegalCoordinateException : public exception {
   const char * theCoordinate(int x, int y) const throw () {
      return x + "," + y;
   }
};

struct IllegalCharException : public exception {
   const char theChar(char a) const throw () {
      return a;
   }
};

Board::Board(){
    this->size = 0;
    this->board = nullptr;
}

Board::Board(int size){
    this->size = size;
    board = new char*[size];
    for(int i = 0; i < size; i++){
        board[i] = new char[size];
        for(int j = 0 ; j < size ; j++)
            board[i][j] = '.';
    }
}

Board::Board(const Board & cp){
    Board tmp;
    tmp.size = cp.size;
    tmp.board = new char*[cp.size];
    for(int i = 0; i < cp.size; i++){
        tmp.board[i] = new char[size];
        for(int j = 0 ; j < cp.size ; j++)
            tmp[{i,j}] = cp[{i,j}];
    }
}

char& Board::operator[](list<int> coor){
    if(coor.size() != 2)
        throw "wrong input";
	int a = coor.front();
	int b = coor.back();
		return this->board[a][b];
}

const char& Board::operator[](list<int> coor) const{
    if(coor.size() != 2)
        throw "wrong input";
	int a = coor.front();
	int b = coor.back();
		return this->board[a][b];
}

ostream& operator << (ostream& os, Board const & board){
    for(int i = 0 ; i < board.size ; i++){
        for(int j = 0 ; j < board.size ; j++){
            os << board.board[i][j];
        }
        if(i != board.size-1)
        os << endl;
    }
    return os;
}

Board::~Board(){}
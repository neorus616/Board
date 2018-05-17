/*Author: Kostia and Yogev */

#include <iostream>
#include <string>
#include <exception>
#include "Board.h"
using namespace std;

Board::Board(){
    this->size = 0;
    this->board = nullptr;
}

Board::Board(int size){
    if(size < 0)
        size *= -1; 
    this->size = size;
    board = new Cell*[size];
    for(int i = 0; i < size; i++){
        board[i] = new Cell[size];
    }
}

Board::Board(const Board & cp){
    length = cp.size;
    board = new Cell*[cp.size];
    for(int i = 0; i < cp.size; i++){
        board[i] = new Cell[length];
        for(int j = 0 ; j < cp.size ; j++)
            (*this)[{i,j}] = cp[{i,j}];
    }
}

void Board::free(){
    for(int i = 0; i < length; i++)
        delete[] board[i];
    delete[] board;
}

Board& Board::operator=(char const & input){
    if(input != '.')
        throw IllegalCharException(input);
    for(int i = 0; i < length; i++)
        for(int j = 0 ; j < length ; j++)
            (*this)[{i,j}] = '.';
    return *this;
}

Board Board::operator=(Board const & input){
    this->free();
    length = input.length;
    board = new Cell*[input.length];
    for(int i = 0; i < input.length; i++){
        board[i] = new Cell[length];
        for(int j = 0 ; j < input.length ; j++)
            (*this)[{i,j}] = input[{i,j}];
    }
    return *this;
}

Cell& Board::operator[](const Coordinate coor){
    if(coor.x > length-1 || coor.y > length-1 || coor.x < 0 || coor.y < 0)
        throw IllegalCoordinateException(coor);
	int a = coor.x;
	int b = coor.y;
		return this->board[a][b];
}

const Cell& Board::operator[](const Coordinate coor) const{
    if(coor.x > length-1 || coor.y > length-1 || coor.x < 0 || coor.y < 0)
        throw IllegalCoordinateException(coor);
	int a = coor.x;
	int b = coor.y;
		return this->board[a][b];
}

ostream& operator << (ostream & os, Board const & board){
    for(int i = 0 ; i < board.length ; i++){
        for(int j = 0 ; j < board.length ; j++){
            os << board.board[i][j];
        }
        os << endl;
    }
    return os;
}

int Board::size() const{
    return this->length;
}


Board::~Board(){
    this->free();
}


/*Author: Kostia and Yogev */

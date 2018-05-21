/*Author: Kostia and Yogev */

#include <iostream>
#include <string>
#include <exception>
#include "Board.h"
using namespace std;

Board::Board(){
    this->_size = 0;
    this->board = nullptr;
}

Board::Board(int size){
    if(size < 0)
        size *= -1; 
    this->_size = size;
    board = new Cell*[_size];
    for(int i = 0; i < _size; i++){
        board[i] = new Cell[_size];
    }
}

Board::Board(const Board & cp){
    _size = cp._size;
    board = new Cell*[cp._size];
    for(uint i = 0; i < cp._size; i++){
        board[i] = new Cell[_size];
        for(uint j = 0 ; j < cp._size ; j++)
            (*this)[{i,j}] = cp[{i,j}];
    }
}

void Board::free(){
    for(int i = 0; i < _size; i++)
        delete[] board[i];
    delete[] board;
}

Board& Board::operator=(char const & input){
    if(input != '.')
        throw IllegalCharException(input);
    for(uint i = 0; i < _size; i++)
        for(uint j = 0 ; j < _size ; j++)
            (*this)[{i,j}] = '.';
    return *this;
}

Board Board::operator=(Board const & input){
    this->free();
    _size = input._size;
    board = new Cell*[input._size];
    for(uint i = 0; i < input._size; i++){
        board[i] = new Cell[_size];
        for(uint j = 0 ; j < input._size ; j++)
            (*this)[{i,j}] = input[{i,j}];
    }
    return *this;
}

Cell& Board::operator[](const Coordinate coor){
    if(coor.x > _size-1 || coor.y > _size-1)
        throw IllegalCoordinateException(coor);
	int a = coor.x;
	int b = coor.y;
		return this->board[a][b];
}

const Cell& Board::operator[](const Coordinate coor) const{
    if(coor.x > _size-1 || coor.y > _size-1)
        throw IllegalCoordinateException(coor);
	int a = coor.x;
	int b = coor.y;
		return this->board[a][b];
}

ostream& operator << (ostream & os, Board const & board){
    for(int i = 0 ; i < board._size ; i++){
        for(int j = 0 ; j < board._size ; j++){
            os << board.board[i][j];
        }
        os << endl;
    }
    return os;
}

int Board::size() const{
    return this->_size;
}


Board::~Board(){
    this->free();
}


/*Author: Kostia and Yogev */

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
    size = cp.size;
    board = new Cell*[cp.size];
    for(int i = 0; i < cp.size; i++){
        board[i] = new Cell[size];
        for(int j = 0 ; j < cp.size ; j++)
            (*this)[{i,j}] = cp[{i,j}];
    }
}

Board& Board::operator=(char const & input){
    if(input != '.')
        throw IllegalCharException(input);
    for(int i = 0; i < size; i++)
        for(int j = 0 ; j < size ; j++)
            (*this)[{i,j}] = '.';
    return *this;
}

Board Board::operator=(Board const & input){
    size = input.size;
    board = new Cell*[input.size];
    for(int i = 0; i < input.size; i++){
        board[i] = new Cell[size];
        for(int j = 0 ; j < input.size ; j++)
            (*this)[{i,j}] = input[{i,j}];
    }
    return *this;
}

Cell& Board::operator[](list<int> coor){
    if(coor.size() != 2 || coor.front() > size-1 || coor.back() > size-1 || coor.front() < 0 || coor.back() < 0)
        throw IllegalCoordinateException(coor.front(),coor.back());
	int a = coor.front();
	int b = coor.back();
		return this->board[a][b];
}

const Cell& Board::operator[](list<int> coor) const{
    if(coor.size() != 2 || coor.front() > size-1 || coor.back() > size-1 || coor.front() < 0 || coor.back() < 0)
        throw IllegalCoordinateException(coor.front(),coor.back());
	int a = coor.front();
	int b = coor.back();
		return this->board[a][b];
}

ostream& operator << (ostream & os, Board const & board){
    for(int i = 0 ; i < board.size ; i++){
        for(int j = 0 ; j < board.size ; j++){
            os << board.board[i][j];
        }
        os << endl;
    }
    return os;
}

Board::~Board(){
    for(int i = 0; i < size; i++)
        delete[] board[i];
    delete[] board;
}
/*Author: Kostia and Yogev */

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
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

istream& operator >> (istream & is,Board & board){
    string tmp;
    uint counter = 0;
    uint length = 0;
    while(is >> tmp){
        if(!counter){
            length = tmp.length();
            board.free();
            board._size = length;
            board.board = new Cell*[length];
            for(uint i = 0; i < length; i++){
                board.board[i] = new Cell[length];
            }
            board.inputChecker(tmp);
            board.inputInsert(board,tmp,counter);
        }
        else if(counter < length && tmp.length() == length){
            board.inputChecker(tmp);
            board.inputInsert(board,tmp,counter);
        } else{ 
            board.free();
            throw "wrong input";
        }
    }
}

void Board::inputChecker(string & line){
    for(int i = 0 ; i < line.length() ; i++)
        if(line.at(i) != 'X' && line.at(i) != 'O' && line.at(i) != '.')
            throw "wrong input";
}

void Board::inputInsert(Board & board, string & line, uint & counter){
    for(int i = 0 ; i < board._size ; i++){
        board[{counter,i}] = line.at(i);
    }
        counter++;
}

int Board::size() const{
    return this->_size;
}

string Board::draw(int res){
    int pix_per_cell = res / this->size();
    if (pix_per_cell < 4) { throw "resultion too low"; }

    string filename = to_string(res);
    int counter = 0;

    while (is_file_exist(filename)){
        counter++;
        filename = to_string(res) + "_" + to_string(counter);
    }

    filename += ".ppm";
    ofstream out(filename, ios::out | ios::binary);
    out << "P6" << endl << res << " " << res << endl << 255 << endl;

    RGB img[res][res];
    for (int y = 0; y < res; y++){
        for (int x = 0; x < res; x++){
            if ( ( (y % pix_per_cell) == (0 || 1) ) || ( (x % pix_per_cell) == (0 || 1) ) ){
                img[y][x].blue = 0;
                img[y][x].green = 0;
                img[y][x].red = 0;
            }
            else if ()
        }
    }
    return filename;
}

bool is_file_exist(const string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

Board::~Board(){
    this->free();
}


/*Author: Kostia and Yogev */

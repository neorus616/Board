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
    return is;
}

void Board::inputChecker(string & line){
    for(int i = 0 ; i < line.length() ; i++)
        if(line.at(i) != 'X' && line.at(i) != 'O' && line.at(i) != '.')
            throw "wrong input";
}

void Board::inputInsert(Board & board, string & line, uint & counter){
    for(uint i = 0 ; i < board._size ; i++){
        board[{counter,i}] = line.at(i);
    }
        counter++;
}

string Board::draw(int n){
    RGB image[n*n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
                image[i*n + j].red = 200;
                image[i*n + j].green = 200;
                image[i*n + j].blue = 200;
        }
    for(uint i = 0; i < this->size(); i++){
        for(uint j = 0; j < this->size(); j++){
            if((*this)[{i,j}] == 'X'){
                drawx(image, i*(n*n/this->size())+j*n/this->size()+0.99, n/this->size()+0.99);
                }
            else if((*this)[{i,j}] == 'O'){
                drawo(image, i*(n*n/this->size())+j*n/this->size(), n/this->size());
                }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((j>0 && j % (n / this->size()) == 0)){
                image[i*n + j].red = 0;
                image[i*n + j].green = 0;
                image[i*n + j].blue = 0;
            }
            if((i>0 && i % (n / this->size()) == 0)){
                image[i*n + j].red = 0;
                image[i*n + j].green = 0;
                image[i*n + j].blue = 0; 
            }
        }
    }
    string filename = to_string(n);
    int counter = 0;

    while (is_file_exist(filename+".ppm")){
        counter++;
        filename = to_string(n) + "_" + to_string(counter);
    }
    filename += ".ppm";
    ofstream out(filename, ios::out | ios::binary);
    out << "P6" << endl << n << " " << n << endl << 255 << endl;
    out.write(reinterpret_cast<char*>(&image), 3*n*n);
    out.close();
    return filename;
}

void Board::drawx(RGB * image, int x, int n){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; ++j)
            if (i == j || i == j+1 || i+1 == j || (n - i - 1 == j) || (n - i - 2 == j) || (n - i == j)){
                image[x+i*n*this->size()+j].red = 255;
                image[x+i*n*this->size()+j].green = 0;
                image[x+i*n*this->size()+j].blue = 0;
            }
}

void Board::drawo(RGB * image, int x, int n){
    for (int i=0; i<n; ++i)
        for (int j=0; j < n; ++j)
            if(((i-0.5*n)*(i-0.5*n) + (j-0.5*n)*(j-0.5*n) <= 0.5*n*0.5*n+n) &&
                ((i-0.5*n)*(i-0.5*n) + (j-0.5*n)*(j-0.5*n) >= 0.5*n*0.5*n-n)){
                image[x+i*n*this->size()+j].red = 0;
                image[x+i*n*this->size()+j].green = 0;
                image[x+i*n*this->size()+j].blue = 255;
            }
}

int Board::size() const{
    return this->_size;
}

bool Board::is_file_exist(const string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

Board::~Board(){
    this->free();
}


/*Author: Kostia and Yogev */

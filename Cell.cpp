/*Author: Kostia and Yogev */
#include <exception>
#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell(){
    pox = '.';
}

Cell::Cell(const char & input){
    if(input != 'X' && input != 'O' && input != '.')
        throw IllegalCharException(input);
    pox = input;
}

Cell& Cell::operator = (const char & input){
    if(input != 'X' && input != 'O' && input != '.')
        throw IllegalCharException(input);
    this->pox = input;
    return *this;
}

Cell Cell::operator =(const Cell & input){
    this->pox = input.pox;
    return *this;
}

bool operator ==(Cell const & l, char const & r){
    return l.pox == r;
}

bool operator !=(Cell const & l, char const & r){
    return !(l==r);
}

Cell::operator char(){
    return pox;
}

ostream& operator <<(ostream & os, Cell const & c){
    return os << c.pox;
}

Cell::~Cell(){}

/*Author: Kostia and Yogev */

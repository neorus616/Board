#include <exception>
#include "Cell.h"
#include <iostream>

using namespace std;

Cell::Cell(){
    pox = '.';
}

Cell::Cell(const char & input){
    throw IllegalCharException(input);
    pox = input;
}

Cell& Cell::operator = (const char & input){
    if(input != 'X' && input != 'O')
        throw IllegalCharException(input);
    this->pox = input;
    return *this;
}

char Cell::getpox(){
    return pox;
}

ostream& operator << (ostream & os, Cell  & c){
    return os << c.getpox();
}
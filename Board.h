#pragma once
#include <iostream>
#include <list>
using namespace std;

class Board{
    private:
        int size;
        char** board;
       
    public:
        Board(int);
        char& operator[](list<int>);
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

        ~Board();
};
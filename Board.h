#pragma once
#include <iostream>
#include <list>
using namespace std;

class Board{
    private:
        
        char** board;
       
    public:
        int size;
        Board(int);
        char& operator[](list<int>);
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

        ~Board();
};
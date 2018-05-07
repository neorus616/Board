#pragma once
#include <iostream>
using namespace std;

class Board{
    private:
        int size;
        char** board;
       
    public:
        // Board();
        Board(int);
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

        ~Board();
};
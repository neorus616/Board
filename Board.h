#pragma once
#include <iostream>
#include <list>
using namespace std;

class Board{
    private:
        int size;
        char** board;
       
    public:
        Board();
        Board(const Board & cp);
        Board(int);
        char& operator[](list<int>);
        const char& operator[](list<int>) const;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

        ~Board();
};
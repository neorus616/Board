#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Cell.h"
using namespace std;

class Board{
    private:
        int size;
        Cell** board;
       
    public:
        Board();
        Board(const Board & cp);
        Board(int);
        Board& operator=(char const &);
        Board operator=(Board const & input);
        Cell& operator[](list<int>);
        const Cell& operator[](list<int>) const;
        void free();
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

        ~Board();
};

struct IllegalCoordinateException : public exception {
    int a, b;
    IllegalCoordinateException(int x, int y){
        a = x;
        b = y;
    }
    const string theCoordinate() const throw () {
        string s = to_string(a) + "," + to_string(b);
        return s;
   }
};

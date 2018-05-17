#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Cell.h"
#include "Coordinate.h"
using namespace std;

class Board{
    private:
        int length;
        Cell** board;
       
    public:
        Board();
        Board(const Board & cp);
        Board(int);
        Board& operator=(char const &);
        Board operator=(Board const & input);
        Cell& operator[](const Coordinate);
        const Cell& operator[](const Coordinate) const;
        int size() const;
        void free();
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Board const &);
        friend istream& operator >> (istream & ,Board &);

        ~Board();
};

struct IllegalCoordinateException : public exception {
    Coordinate cor;
    IllegalCoordinateException(Coordinate c){
        Coordinate cor(c);
    }
    const string theCoordinate() const throw () {
        string s = to_string(cor.x) + "," + to_string(cor.y);
        return s;
   }
};

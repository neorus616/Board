#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Cell.h"
#include "Coordinate.h"
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB(): red(255), green(255), blue(255){}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board{
    private:
        int _size;
        Cell** board;
        void inputInsert(Board & , string & , uint &);
        void inputChecker(string &);
       
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
        void draw(int);
        void drawx(RGB *, int, int);
        void drawo(RGB *, int, int);
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

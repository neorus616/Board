#pragma once
#include <iostream>
#include <list>
#include <string>
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

struct IllegalCharException : public exception {
    char a;
    IllegalCharException(char x){
        a = x;
    }
    const char theChar() const throw () {
        return a;
   }
};
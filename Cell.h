#pragma once
#include <iostream>

using namespace std;

class Cell{
    private:
       char pox;

    public:
        Cell();
        Cell(const char &);
        Cell& operator = (const char &);
        Cell operator = (const Cell & input);
        operator char();
        friend bool operator == (Cell const &, char const &);
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Cell const &);

        ~Cell();
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
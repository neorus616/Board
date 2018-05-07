#pragma once

class Cell{
    private:
       char pox;

    public:
        Cell();
        Cell(const char &);
        Cell& operator = (const char &);
        char getpox();
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Stream<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
        friend ostream& operator << (ostream &, Cell &);

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
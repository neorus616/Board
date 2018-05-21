#include <iostream>
#include <string>
#include "TicTacToe.h"
using namespace std;


TicTacToe::TicTacToe(int size){
    	cout << "board is coming" << endl;
		system("find main.cpp");
    this->size = size;
    game = new Board(size);;
    _winner = NULL;
}

const Board& TicTacToe::board() const{
    return *game;
}

Player& TicTacToe::winner() const{
    return *_winner;
}

void TicTacToe::play(Player& xPlayer, Player& oPlayer){
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    *game = '.';
    _winner = NULL;
    while(1){
        turn(game,xPlayer,oPlayer);
        if(_winner)
            break;
        turn(game,oPlayer,xPlayer);
        if(_winner)
           break;
    }
}

void TicTacToe::turn(Board * game,Player& current, Player& other){
    Coordinate move;
    try{
            move = current.play(*game);
        }catch(...){
            _winner = &other;
            return;
        }
        if((*game)[move] == '.')
           (*game)[move] = current.getChar();
        else {
            _winner = &other;
            return;
        }
        if(winMove(move,current.getChar())){
            _winner = &current;
        }
}

bool TicTacToe::winMove(Coordinate move,char myC){
    bool col = true;
    bool row = true;
    bool diag = true;
    bool mdiag = true;
    for(uint i = 0 ; i < size ; i++)
        if((*game)[{move.x,i}] != myC)
            col = false;
    
    for(uint i = 0 ; i < size ; i++)
        if((*game)[{i,move.y}] != myC)
            row = false;
    
    if(move.x == (size - move.y - 1)){
        for(uint i = 0, j = size-1 ; i < size ; i++,j--)
            if((*game)[{i,j}] != myC)
                mdiag = false;
    } else mdiag = false;
    
    if(move.x == move.y){
        for(uint i = 0, j = 0 ; i < size ; i++,j++)
            if((*game)[{i,j}] != myC)
                diag = false;
    } else diag = false;
    
    
    
    return col||row||diag||mdiag;
}

TicTacToe::~TicTacToe(){
    delete game;
}

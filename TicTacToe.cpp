#include <iostream>
#include <string>
#include "TicTacToe.h"
using namespace std;


TicTacToe::TicTacToe(int size){
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
    while(1){
        Coordinate move;
        try{
            move = xPlayer.play(*game);
        }catch(...){
            _winner = &oPlayer;
            break;
        }
        if((*game)[move] == '.')
           (*game)[move] = xPlayer.getChar();
        else {
            _winner = &oPlayer;
            break;
        }
        if(winMove(move,xPlayer.getChar())){
            _winner = &xPlayer;
            break;
        }
        
        try{
            move = oPlayer.play(*game);
        }catch(...){
            _winner = &xPlayer;
            break;
        }
        if((*game)[move] == '.')
           (*game)[move] = oPlayer.getChar();
        else {
            _winner = &xPlayer;
            break;
        }
        if(winMove(move,oPlayer.getChar())){
            _winner = &oPlayer;
            break;
        }
    }
}

bool TicTacToe::winMove(Coordinate move,char myC){
    bool col = true;
    bool row = true;
    bool diag = true;
    bool mdiag = true;
    for(uint i = 0 ; i < size ; i++){
        if((*game)[{move.x,i}] != myC)
            col = false;
    }
    for(uint i = 0 ; i < size ; i++){
        if((*game)[{i,move.y}] != myC)
            row = false;
    }
    if(move.x == move.y){
        for(uint i = 0, j = 0 ; i < size ; i++,j++)
            if((*game)[{i,j}] != myC)
                diag = false;
        for(uint i = 0, j = size-1 ; i < size ; i++,j--)
            if((*game)[{i,j}] != myC)
                mdiag = false;
    } else {
        diag = false;
        mdiag = false;
    }
    return col||row||diag||mdiag;
}

TicTacToe::~TicTacToe(){
    
}
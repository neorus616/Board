#include "Player.h"
using namespace std;


Player::Player(){}


const string Player::name() const{
     return "lolik"; 
     }

const Coordinate Player::play(const Board& board){
    
}

void Player::setChar(char myC){
    myChar = myC;
}

const char Player::getChar() const{
    return myChar;
}
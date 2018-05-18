#include "Player.h"
using namespace std;


Player::Player(){
    myChar = 'O';
}


Player::Player(char myChar){
    this->myChar = myChar;
}

const string Player::name() const{
     return "lolik"; 
     }

const Coordinate Player::play(const Board& board){
    
}

const char Player::getChar() const{
    return myChar;
}
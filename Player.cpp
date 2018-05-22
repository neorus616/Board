#include "Player.h"
using namespace std;


Player::Player(){}

void Player::setChar(char myC){
    myChar = myC;
}

const char Player::getChar() const{
    return myChar;
}

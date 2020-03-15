#include "player.h"

Player::Player(){
    
    health = 10;
    posX = 0;
    posY = 0;
    entityID = 0;
    entityName = "Player";
    symbol = '@';

    downKey = 258;
    upKey = 259;
    leftKey = 260;
    rightKey = 261;
}

Player::Player(int newHealth, int newPosX, int newPosY, int newEntityID, std::string newPlayerName, char newSymbol) {

    if(newHealth > 0) {
        health = newHealth;
    }

    if(newPosX >= 0) {
        posX = newPosX;
    }

    if(newPosY >= 0) {
        posY = newPosY;
    }

    if(newEntityID >= 0){
        entityID = newEntityID;
    }
    
    entityName = newPlayerName;
    symbol = newSymbol;
    
    downKey = 258;
    upKey = 259;
    leftKey = 260;
    rightKey = 261;
}

void Player::controlPlayer(int commandCode) {
    movePlayer(commandCode);
}

void Player::movePlayer(int commandCode) {
    
    if(commandCode == downKey) {
        posY++;
    }
    if(commandCode == upKey && posY > 0) {
        posY--;
    }
    if(commandCode == leftKey && posX > 0) {
        posX--;
    }
    if(commandCode == rightKey) {
        posX++;
    }

}

void Player::setUpKey(int newKeyCode) {
    if(newKeyCode >= 0){
        upKey= newKeyCode;
    }
}
void Player::setDownKey(int newKeyCode) {
    if(newKeyCode >= 0){
        downKey= newKeyCode;
    }
}
void Player::setLeftKey(int newKeyCode) {
    if(newKeyCode >= 0){
        leftKey= newKeyCode;
    }
}
void Player::setRightKey(int newKeyCode) {
    if(newKeyCode >= 0){
        rightKey= newKeyCode;
    }
}
///getters

int Player::getUpKey()const {
    return upKey;
}
int Player::getDownKey()const {
    return downKey;
}
int Player::getLeftKey()const {
    return leftKey;
}

int Player::getRightKey()const {
    return rightKey;
}
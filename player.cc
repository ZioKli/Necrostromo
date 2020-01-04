#include "player.h"

Player::Player(){
    health = 10;
    posX = 0;
    posY = 0;
    entityID = 0;
    entityName = "Player";
    symbol = '@';
}

Player::Player(int newHealth, int newPosX, int newPosY, int newEntityID, string newPlayerName, char newSymbol) {

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
    
}

void Player::controlPlayer(int commandCode) {
    movePlayer(commandCode);
}
void Player::movePlayer(int commandCode) {

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
int Player::getUpKey() {
    return upKey;
}
int Player::getDownKey() {
    return downKey;
}
int Player::getLeftKey() {
    return leftKey;
}
int Player::getRightKey() {
    return rightKey;
}
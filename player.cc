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
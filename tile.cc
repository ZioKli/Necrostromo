#include "tile.h"


Tile::Tile(){
    symbol = '.';
    xPos = 0;
    yPos = 0;
}

Tile::Tile(char newSymbol, int NewXPos, int newYPos){
    symbol = newSymbol;
    xPos = NewXPos;
    yPos = newYPos;
}


void Tile::setSymbol(char newSymbol){
    symbol = newSymbol;
}

void Tile::setPosY(int newY){
    if(newY >= 0) {
        yPos = newY;
    }
}

void Tile::setPosX(int newX){
        if(newX >= 0) {
        xPos = newX;
    }
}
void Tile::addNewEntityID(int newID){
    if(newID >= 0){
        entityIDs.push_back(newID);
    }
}


vector<int> Tile::getEntityIDs() const {
    return entityIDs;
}
char Tile::getSymbol() const{
    return symbol;
}

int Tile::getYPos() const{
    return yPos;
}

int Tile::getXPos() const{
    return xPos;
}

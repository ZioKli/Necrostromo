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


char Tile::getSymbol(){
    return symbol;
}

int Tile::getYPos(){
    return yPos;
}

int Tile::getXPos(){
    return xPos;
}

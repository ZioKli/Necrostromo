#include "tile.h"


Tile::Tile(){
    symbol = '.';
}

Tile::Tile(char newSymbol){
    symbol = newSymbol;
}

void Tile::setSymbol(char newSymbol){
    symbol = newSymbol;
}

char Tile::getSymbol(){
    return symbol;
}
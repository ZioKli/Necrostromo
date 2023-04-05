#include "tile.h"

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

char Tile::getSymbol() const{
    return symbol;
}

int Tile::getYPos() const{
    return yPos;
}

int Tile::getXPos() const{
    return xPos;
}

void Tile::item_move(Item *itm, Tile &other){
    bool found = false;
    for(size_t i = 0; i < items.size(); i++){
        if(itm == items[i]){
            items.erase(items.begin() + i);
            found = true;
        }
    }
    if(!found){
        return;
    }
    other.add_item(itm);
}
void Tile::entity_move(Entity *ent, Tile &other){
    bool found = false;
    for(size_t i = 0; i < entities.size(); i++){
        if(ent == entities[i]){
            entities.erase(entities.begin() + i);
            found = true;
        }
    }
    if(!found){
        return;
    }
    other.add_entity(ent);
}

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

char Tile::getSymbol() const{
    return symbol;
}

int Tile::getYPos() const{
    return yPos;
}

int Tile::getXPos() const{
    return xPos;
}

void Tile::item_move(Item itm, Tile &other){
    dlist<Item>::iterator item_loc;
    item_loc = has_item_at(itm);
    if(item_loc != items.end()){
        other.add_item(itm);
        items.remove(item_loc);
    }
}
void Tile::entity_move(Entity ent, Tile &other){
    dlist<Entity>::iterator entityLoc;
    entityLoc = has_entity_at(ent);
    if(entityLoc != entities.end()){
        other.add_entity(ent);
        entities.remove(entityLoc);
    }
}

dlist<Item>::iterator Tile::has_item_at(Item itm) {
    for(dlist<Item>::iterator it = items.begin(); it != items.end(); it++){
        if (itm == *it){
            return it;
        }
    }
    return items.end();
}

dlist<Entity>::iterator Tile::has_entity_at(Entity ent){
    for(dlist<Entity>::iterator it = entities.begin(); it != entities.end(); it++){
        if(ent == *it){
            return it;
        }
    }
    return entities.end();
}


#include <string>
#include <cstdlib>
#include "entity.h"
#include "tile.h"
using namespace std;
///default constructor

///constructor used for a specific position, name, and symbol
Entity::Entity(string newName, int newId, int newHealth, char newSymbol, int newPosY, int newPosX){
    posX = newPosX;
    posY = newPosY;
    entityName = newName;
    symbol = newSymbol;
    health = newHealth;
    entityID = newId;
}
Entity::Entity(Tile newTile, string newName, int newId, int newHealth, char newSymbol){
    
}

///sets health to a new value if it is greater than or equal to zero. 
///may change to accept negative values as an overkill mechanic or simply to trigger death 
void Entity::setHealth(int newHealth){
    if(newHealth >= 0){
        health = newHealth;
    }
}
///directly sets position X to a new value greater than or equal to zero
void Entity::setPosX(int newPosX){
    if(newPosX >= 0) {
        posX = newPosX;
    }
}
///directly sets position Y to a new value greater than or equal to zero
void Entity::setPosY(int newPosY){
    if(newPosY >= 0) {
        posY = newPosY;
    }
}

void Entity::setEntityID(int newID){
    if(newID >= 0){
        entityID = newID;
    }
}
///sets the symbol to a new symbol
void Entity::setSymbol(char newSymbol){
    symbol = newSymbol;
}
///gives the entity a new name as long as the new name is not an empty string
void Entity::setEntityName(string newName){
    if(newName != ""){
        entityName = newName;
    }
}



///returns the current health of the entity
int Entity::getHealth() const{
    return health;
}
///returns the current Position X of the entity
int Entity::getPosX() const{
    return posX;
}
///returns the current Position Y of the entity
int Entity::getPosY() const{
    return posY;
}
int Entity::getEntityID(){
    return entityID;
}
///returns the current symbol of the entity
char Entity::getSymbol() const{
    return symbol;
}
///returns the name of the entity;
string Entity::getEntityName() const{
    return entityName;
}

#include <cstdlib>
#include <vector>
#include "item.h"
#include "dependencies/dlist.h"
#include "entity.h"
#ifndef TILE_H
#define TILE_H

/**
 * todo: 
 * add pointers to 8 adjacent tiles
 * add linked list of items and entities currently on this tile
 */
class Tile{
    public:
    ///setters
    void setSymbol(char newSymbol);
    void setPosY(int newY);
    void setPosX(int newX);

    ///getters
    char getSymbol() const;
    int getYPos() const;
    int getXPos() const;
    ///constructors
    Tile();
    Tile(char newSymbol, int NewXPos, int newYPos);

    ///general functions
    void item_move(Item itm, Tile &other);
    void entity_move(Entity ent, Tile &other);

    void add_entity(Entity newEnt){
        entities.rear_insert(newEnt);
    }

    void add_item(Item newItem){
        items.rear_insert(newItem);
    }
    private:
    dlist<Item> items;
    dlist<Entity> entities;
    dlist<Item>::iterator has_item_at(Item itm);
    dlist<Entity>::iterator has_entity_at(Entity ent);
    char symbol;
    int xPos;
    int yPos;
    
    /// references to the tiles adjacent and diagonal to this one 

    /*
    *Things to add 
    * references to all entities 
    * references to all equipment
    * references to all consumables
    * hierarchy of symbols to display depending on what is on the tile
    * 
    */
};
#endif
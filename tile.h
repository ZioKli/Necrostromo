
#include <cstdlib>
#include <vector>
#ifndef TILE_H
#define TILE_H

using namespace std;

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

    private:
    char symbol;
    int xPos;
    int yPos;
    /// references to the tiles adjacent and diagonal to this one 

    /*
    *Things to add 
    * X and Y coordinates of this tile on current screen
    
    * references to all entities 
    * references to all equipment
    * references to all consumables
    * hierarchy of symbols to display depending on what is on the tile
    * 
    */
};
#endif
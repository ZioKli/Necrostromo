
#ifndef TILE_H
#define TILE_H
#include <cstdlib>
using namespace std;


class Tile{
    public:
    ///setters
    void setSymbol(char newSymbol);

    ///getters
    char getSymbol();
    ///constructors
    Tile();
    Tile(char newSymbol);

    private:
    char symbol;
    /*
    *Things to add 
    * X and Y coordinates of this tile on current screen
    * references to the tiles adjacent and diagonal to this one 
    * references to all entities 
    * references to all equipment
    * references to all consumables
    * hierarchy of symbols to display depending on what is on the tile
    * 
    */
};
#endif
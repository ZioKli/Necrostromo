
#include <vector>
#include <cstdlib>
#include "tile.h"

#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board{
    public:

    ///setters
    /*
    *sets the tile at positon (x,y) to be a new tile
    */
    void SetTileAt(size_t x, size_t y, Tile newTile);

    ///getters
    Tile getTileAt(size_t xPos, size_t yPos);
    size_t getMapWidth() const;
    size_t getMapHeight() const;
    
    /*
    *returns a reference to the entire map. 
    */
    vector<vector<Tile>>& getMap();

    ///constructors
    
    /*
    * default constructor that builds a board of 129 by 29 with all tiles displaying '.' 
    */
    Board();

    /*
    * constructor using a noisemap to build the board
    */
    Board(vector<vector<double>> noiseMap);
    
    /*
    *constructor which takes in a number of columns and a number of rows and then creates a board using those and the provided default tile.
    */
    Board(size_t columns, size_t rows, Tile defaultTile);
    
    private:
    size_t mapWidth;
    size_t mapHeight;
    vector<vector<Tile>> map;
};

#endif
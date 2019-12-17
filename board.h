
#include <vector>
#include <cstdlib>
#include "tile.h"

#ifndef BOARD_H
#define BOARD_H

using namespace std;

class Board{
    public:

    ///setters
    void SetTileAt(size_t x, size_t y, Tile newTile);

    ///getters
    Tile getTileAt(size_t xPos, size_t yPos);
    vector<vector<Tile>>& getMap();

    ///constructors
    Board();
    Board(size_t xSize, size_t ySize, Tile defaultTile);
    
    private:
    size_t mapWidth;
    size_t mapHeight;
    vector<vector<Tile>> map;
};

#endif
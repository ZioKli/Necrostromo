
#include "board.h"
///sets a tile at an x and y coordinate to be a specific tile
void Board::SetTileAt(size_t x, size_t y, Tile newTile){
    map.at(x).at(y) = newTile;
}
///returns a tile at a specific x,y coordinate
Tile Board::getTileAt(size_t xPos, size_t yPos){
    return map.at(xPos).at(yPos);
}

/// returns a reference to the entire map which is a vector of vectors each containing a row of tiles; 
vector<vector<Tile>>& Board::getMap(){
    return map;
}
/// creates a default board with basic tiles in a size that fits the default console window size
Board::Board(){
    mapWidth = 119;
    mapHeight = 29;
    for(size_t y = 0; y < mapHeight; y++){
        vector<Tile> row;
        for(size_t x = 0; x < mapWidth; x++){
            row.push_back(Tile('.', x, y));
        }
        map.push_back(row);
    }
}
///creates a board of a given size, using a given default tile;
Board::Board(size_t xSize, size_t ySize, Tile defaultTile){
    mapWidth = xSize;
    mapHeight = ySize;
    for(size_t y = 0; y < mapHeight; y++){
        vector<Tile> row;
        for(size_t x = 0; x < mapWidth; x++){
            defaultTile.setPosX(x);
            defaultTile.setPosY(y);
            row.push_back(defaultTile);
        }
        map.push_back(row);
    }
}
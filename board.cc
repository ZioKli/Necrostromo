
#include "board.h"

void Board::SetTileAt(size_t x, size_t y, Tile newTile){
    map.at(x).at(y) = newTile;
}

Tile Board::getTileAt(size_t xPos, size_t yPos){
    return map.at(xPos).at(yPos);
}

vector<vector<Tile>>& Board::getMap(){
    return map;
}

Board::Board(){
    mapWidth = 119;
    mapHeight = 29;
    for(size_t y = 0; y < mapHeight; y++){
        vector<Tile> row;
        for(size_t x = 0; x < mapWidth; x++){
            row.push_back(Tile());
        }
        map.push_back(row);
    }
}

Board::Board(size_t xSize, size_t ySize, Tile defaultTile){
    mapWidth = xSize;
    mapHeight = ySize;
    for(size_t y = 0; y < mapHeight; y++){
        vector<Tile> row;
        for(size_t x = 0; x < mapWidth; x++){
            row.push_back(defaultTile);
        }
        map.push_back(row);
    }
}
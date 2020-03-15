
#include "board.h"
using namespace std;
///sets a tile at an x and y coordinate to be a specific tile
void Board::SetTileAt(size_t x, size_t y, Tile newTile){
    map.at(x).at(y) = newTile;
}
///returns a tile at a specific x,y coordinate
Tile Board::getTileAt(size_t xPos, size_t yPos){
    return map.at(yPos).at(xPos);
}

size_t Board::getMapWidth() const {
    return mapWidth;
}

size_t Board::getMapHeight() const {
    return mapHeight;
}

/// returns a reference to the entire map which is a vector of vectors each containing a row of tiles; 
vector<vector<Tile>>& Board::getMap() {
    
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
Board::Board(size_t columns, size_t rows, Tile defaultTile){
    mapWidth = columns;
    mapHeight = rows;
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
Board::Board(vector<vector<double>> noiseMap) {
    ///to-do
    ///array for tileset to be used
    Tile water, shore, grass, stone;
    double val = 0;
    water.setSymbol('~');
    shore.setSymbol(',');
    grass.setSymbol('.');
    stone.setSymbol('^');
    
    for(size_t line = 0; line < noiseMap.size(); line++){
        vector<Tile> row;
        for(size_t column = 0; column < noiseMap.at(line).size(); column++){
            val = noiseMap.at(line).at(column);
            if(val < .5) {
                water.setPosX(column);
                water.setPosY(line);
                row.push_back(water);
            }
            else if(val < .52){
                shore.setPosX(column);
                shore.setPosY(line);
                row.push_back(shore);
            }
            else if(val < .9){
                grass.setPosX(column);
                grass.setPosY(line);
                row.push_back(grass);
            }
            else if(val <= 1){
                stone.setPosX(column);
                stone.setPosY(line);
                row.push_back(stone);
            }
        }
        map.push_back(row);
    }
}
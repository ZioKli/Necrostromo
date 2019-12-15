

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
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
};

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

int main() {


    bool quit = false;
    string command = "";
    Board testBoard; 
    Tile testTile;
    while(!quit) {
        for(vector<Tile> row : testBoard.getMap()) {
            for (Tile t: row) {
                cout << t.getSymbol();
            }
            cout << endl;
        }
        cout << "enter a command (y/n) to continue or quit: ";
        cin >> command; 
        if(command != "y" && command !="Y"){
            if (command == "n" || command == "N") {
                quit = true;
            }
            else {
                exit(0);
            }
        }
    }
    cout << "you exited properly" << endl;
    return 0;
}

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

Tile::Tile(){
    symbol = '.';
}

Tile::Tile(char newSymbol){
    symbol = newSymbol;
}

void Tile::setSymbol(char newSymbol){
    symbol = newSymbol;
}

char Tile::getSymbol(){
    return symbol;
}


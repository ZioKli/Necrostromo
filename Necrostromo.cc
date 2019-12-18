
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include "board.h"
#include "tile.h"
#include "entity.h"

using namespace std;

void drawScreen(Board gameBoard, vector<Entity> const &entities);

int main() {
    bool quit = false;
    string command = "";
    Board testBoard; 
    Tile testTile;
    Entity player;
    player.setPosX(4);
    player.setPosY(4);
    vector<Entity> entities;
    entities.push_back(player);
    testTile.setSymbol('.');
    testBoard = Board(119, 29, testTile);
    while(!quit) {
        drawScreen(testBoard, entities);
        cin >> command;
        if(command == "w" || command == "W"){
            entities.at(0).setPosY(entities.at(0).getPosY() + 1);
        }
    }
    return 0;
}

void drawScreen(Board gameBoard, vector<Entity> const &entities){
    ///draw the base game board
    ///draw entities over game board
    ///
    string screen ="";
    for(vector<Tile> row : gameBoard.getMap()) {
        for (Tile t: row) {
            screen += t.getSymbol();
        }
        screen += "\n";
    }

    for(Entity ent : entities) {
        int x = ent.getPosX();
        int y = ent.getPosY();
        char sym = ent.getSymbol();
        size_t indexInString = ((y * gameBoard.getMapWidth()) + y) + x;
        screen.at(indexInString) = sym;
    }
    
    cout << screen;
}
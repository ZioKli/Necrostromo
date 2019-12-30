
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include "board.h"
#include "tile.h"
#include "entity.h"
#include "player.h"

using namespace std;

void drawScreen(Board gameBoard, vector<Entity> const &entities);
void controlPlayer();


int main() {
    bool quit = false;
    string command = "";
    Board testBoard; 
    Tile testTile;
    Player pc;
    vector<Entity> entities;
    testTile.setSymbol('.');
    testBoard = Board(119, 29, testTile);
    while(!quit) {
        drawScreen(testBoard, entities);
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


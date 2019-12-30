
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include <ncurses.h>
#include <stdio.h>

#include "board.h"
#include "tile.h"
#include "entity.h"
#include "player.h"

using namespace std;

void drawScreen(Board gameBoard, vector<Entity> const &entities);
void controlPlayer(Player player);
void movePlayer(Player &pc, int commandCode);

int main() {
    /// initialize ncurses
    initscr();  /// initializes the window
    cbreak();///processes one key at a time with no buffer
    noecho(); /// prevents the input key from being echoed to the user 
    keypad(stdscr, TRUE); /// allows special keys, including the arrow keys, backspace, and delete, to be used.

    
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
        controlPlayer(pc);
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

void controlPlayer(Player player){
    int command = 0;
    command = getch();
}

void movePlayer(Player &pc, int commandCode){
    ///must be able to be remappable
    ///hardcoded for now. a config class could be used to hold the information for the control;
    
}
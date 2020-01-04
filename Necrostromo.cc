
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
    curs_set(0);
    
    bool quit = false;
    // string command = "";
    Board testBoard; 
    Tile testTile;
    Player pc;
    int rows, columns;
    getmaxyx(stdscr, rows, columns);
    pc.setPosX(43);
    pc.setPosY(20);
    vector<Entity> entities;
    entities.push_back(pc);
    testTile.setSymbol('.');
    testBoard = Board(columns, rows, testTile);
    while(!quit) {
        drawScreen(testBoard, entities);
    }
    return 0;
}

void drawScreen(Board gameBoard, vector<Entity> const &entities){
    ///draw the base game board

    move(0,0);
    for(size_t row = 0; row < gameBoard.getMap().size(); row++) {
        for (size_t column = 0; column < gameBoard.getMap().at(row).size(); column++){
            char symbol = gameBoard.getTileAt(column, row).getSymbol();
            addch(symbol);
        }
    }

    for(Entity ent : entities) {
        int x = ent.getPosX();
        int y = ent.getPosY();
        char sym = ent.getSymbol();
        mvaddch(y, x, sym);
        // screen.at(indexInString) = sym;
    }
    refresh();
    // printw(screen);
}
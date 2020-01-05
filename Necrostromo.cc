
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

void drawScreen(Board &gameBoard, vector<Entity> const &entities, Player pc);
void controlPlayer(Player player);
void movePlayer(Player &pc, int commandCode);

int main() {
    /// initialize ncurses
    initscr();  /// initializes the window
    cbreak();///processes one key at a time with no buffer
    noecho(); /// prevents the input key from being echoed to the user 
    keypad(stdscr, TRUE); /// allows special keys, including the arrow keys, backspace, and delete, to be used.
    curs_set(0);
    int rows, columns;
    getmaxyx(stdscr, rows, columns);
    
    bool quit = false;
    Board testBoard; 
    Tile testTile;
    Player pc;
    vector<Entity> entities;
    int commandCode = 0;
    int quitKey = 113;
    
    testTile.setSymbol('.');
    testBoard = Board(columns, rows, testTile);
    
    while(!quit) {
        drawScreen(testBoard, entities, pc);
        commandCode = getch();
        pc.controlPlayer(commandCode);
    
        if(commandCode == quitKey){
            quit = true;
            nocbreak();
            keypad(stdscr, false);
            echo();
            endwin();
        }
        commandCode = 0;   
    }
    return 0;
}

void drawScreen(Board  &gameBoard, vector<Entity> const &entities, Player pc){ 
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
    }

    char playerSymbol = pc.getSymbol();
    mvaddch(pc.getPosY(), pc.getPosX(), playerSymbol);
    refresh();
}

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

#include <ncurses.h>
#include <stdio.h>

#include "data/generator.h"
#include "data/board.h"
#include "data/tile.h"
#include "data/entity.h"
#include "data/player.h"

using namespace std;

void drawScreen(Board &gameBoard, vector<Entity> const &entities, Player const &pc);
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

    Generator gen; 
    gen.generateNoiseMap2D(rows, columns, 1224);

    testBoard = Board(gen.getNoiseMap2D());

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

void drawScreen(Board  &gameBoard, vector<Entity> const &entities, Player const &pc){ 
    ///draw the base game board
    move(0,0);///resets the cursor to the top left of the screen 
    for(size_t row = 0; row < gameBoard.getMap().size(); row++) {
        for (size_t column = 0; column < gameBoard.getMap().at(row).size(); column++){
            char symbol = gameBoard.getTileAt(column, row).getSymbol(); ///iterates through the game board and gets the symbol of each tile
            addch(symbol); /// prints that symbol at its y,x coordinate
        }
    }

    for(Entity ent : entities) {
        int x = ent.getPosX();
        int y = ent.getPosY();
        char sym = ent.getSymbol();
        mvaddch(y, x, sym); ///goes through our list of entities and prints them all at their y,x positions
    }

    char playerSymbol = pc.getSymbol();///gets the player symbol
    mvaddch(pc.getPosY(), pc.getPosX(), playerSymbol);/// prints the player's symbol at its current y,x position
    refresh(); ///updates the screen to display all the changes
}
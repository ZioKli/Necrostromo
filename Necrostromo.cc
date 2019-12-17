
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "board.h"
#include "tile.h"
#include "entity.h"
using namespace std;

int main() {


    // bool quit = false;
    // string command = "";
    // Board testBoard; 
    // Tile testTile;
    Entity player;
    player = Entity(15, 24, string("stevey"), '%');
    int health;
    int x;
    int y;
    char symbol;
    string name;
    
    cout << player.getHealth() << endl;
    cout << player.getPosX() << endl;
    cout << player.getPosY() << endl;
    cout << player.getSymbol() << endl;
    cout << player.getEntityName() << endl;

    cout << "enter new health: ";
    cin >> health;
    cout << "enter new x pos: ";
    cin >> x;
    cout << "enter new y pos: ";
    cin >> y;
    cout << "enter new name: ";
    cin >> name;
    cout << "enter new symbol: ";
    cin >> symbol;

    player.setEntityName(name);
    player.setHealth(health);
    player.setPosX(x);
    player.setPosY(y);
    player.setSymbol(symbol);

    cout << player.getHealth() << endl;
    cout << player.getPosX() << endl;
    cout << player.getPosY() << endl;
    cout << player.getSymbol() << endl;
    cout << player.getEntityName() << endl;



    // while(!quit) {
    //     testTile.setSymbol('.');
    //     testBoard = Board(119, 29, testTile);
    //     string screen ="";
    //     for(vector<Tile> row : testBoard.getMap()) {
    //         for (Tile t: row) {
    //             screen += t.getSymbol();
    //         }
    //         screen += "\n";
    //     }
    //     screen += "enter a command (y/n) to continue or quit: ";
    //     cout << screen;
    //     cin >> command; 
    //     if(command != "y" && command !="Y"){
    //         if (command == "n" || command == "N") {
    //             quit = true;
    //         }
    //         else {
    //             exit(0);
    //         }
    //     }
    // }
    // cout << "you exited properly" << endl;
    return 0;
}


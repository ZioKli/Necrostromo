
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include "board.h"
#include "tile.h"
using namespace std;

int main() {


    bool quit = false;
    string command = "";
    Board testBoard; 
    Tile testTile;
    while(!quit) {
        // for(vector<Tile> row : testBoard.getMap()) {
        //     for (Tile t: row) {
        //         cout << t.getSymbol();
        //     }
        //     cout << endl;
        // }
        string screen ="";
        for(vector<Tile> row : testBoard.getMap()) {
            for (Tile t: row) {
                screen += t.getSymbol();
            }
            screen += "\n";
        }
        cout << screen;


        
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


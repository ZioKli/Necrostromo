
#ifndef TILE_H
#define TILE_H
#include <cstdlib>
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
#endif
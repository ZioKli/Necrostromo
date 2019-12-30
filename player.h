#include "entity.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
class Player : public Entity{
    
    public:
    Player();
    
    Player(int newHealth, int newPosX, int newPosY, int newEntityID, string newPlayerName, char newSymbol);

    ///equipment list
    ///inherit body parts? 
};
#endif
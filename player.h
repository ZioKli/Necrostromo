#include "entity.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
class Player : public Entity{
    
    public:
    ///constructors
    Player();
    Player(int newHealth, int newPosX, int newPosY, int newEntityID, string newPlayerName, char newSymbol);
    
    ///setters
    void setUpKey(int newKeyCode);
    void setDownKey(int newKeyCode);
    void setLeftKey(int newKeyCode);
    void setRightKey(int newKeyCode);

    ///getters
    int getUpKey();
    int getDownKey();
    int getLeftKey();
    int getRightKey();
    
    private:
    ///control codes
    int upKey;
    int downKey;
    int leftKey;
    int rightKey;

    ///equipment list
    ///inherit body parts?
    void controlPlayer(int commandCode);
    void movePlayer(int commandCode);
};
#endif
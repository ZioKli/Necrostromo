#include "entity.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
class Player : public Entity{
    
    public:
    ///constructors

    /*
    *Default constructor. Player symbol defaults to @, health defaults to 10, position defaults to 0,0. id defaults to 0. Name defaults to "Player"
    */
    Player();

    /*
    *construction which takes in a health value, positional data, a custom id (0 should be used), a name, and a custom symbol.
    */
    Player(int newHealth, int newPosX, int newPosY, int newEntityID, string newPlayerName, char newSymbol);
    
    ///setters

    /*
    * sets key if provided value is positive
    */
    void setUpKey(int newKeyCode);
    
    /*
    * sets key if provided value is positive
    */
    void setDownKey(int newKeyCode);
    
    /*
    * sets key if provided value is positive
    */
    void setLeftKey(int newKeyCode);
    
    /*
    * sets key if provided value is positive
    */    
    void setRightKey(int newKeyCode);

    ///getters
    
    /*
    * returns the current key code.
    */
    int getUpKey() const;

    /*
    * returns the current key code.
    */
    int getDownKey() const;

    /*
    * returns the current key code.
    */
    int getLeftKey() const;

    /*
    * returns the current key code.
    */
    int getRightKey() const;

    ///control functions

    /*
    *Handles all of the character specific commands. mainly used as a handler to pass the command code to the correct functions to minimize how many if statements
    *are triggered by the average command 
    */
    void controlPlayer(int commandCode);

    /*
    *used to change the player's position using keyboard input.
    */
    void movePlayer(int commandCode);

    private:
    ///control codes
    int upKey;
    int downKey;
    int leftKey;
    int rightKey;

    ///equipment list
    ///inherit body parts?

};
#endif
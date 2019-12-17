
#include <string>
#include <cstdlib>

#ifndef ENTITY_H
#define ENTITY_H

using namespace std;
class Entity{
    protected:
    int health;
    int posX;
    int posY;
    string entityName;
    char symbol;

    public:
    Entity();
    
    Entity(int newPosY, int newPosX, string newName, char newSymbol);


    void setHealth(int newHealth);
    void setPosX(int newPosX);
    void setPosY(int newPosY);
    void setSymbol(char newSymbol);
    void setEntityName(string newName);
    
    int getHealth() const;
    int getPosX() const;
    int getPosY() const;
    char getSymbol() const;
    string getEntityName() const;
};
#endif
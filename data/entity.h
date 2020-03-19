
#include <string>
#include <cstdlib>

#ifndef ENTITY_H
#define ENTITY_H


class Entity{
    protected:
    int health;
    int posX;
    int posY;
    int entityID;
    std::string entityName;
    char symbol;
    

    public:
    bool operator ==(Entity other){
        return(entityID == other.getEntityID());
    }
    
    Entity(std::string newName = "N/A", int newId = 0, int newHealth = 1, char newSymbol = 'a', int newPosY = 0 , int newPosX = 0);

    Entity(Tile NewTile, std::string newName = "N/A", int newId = 0, int newHealth = 1, char newSymbol = 'a');

    /*
    *sets health to a new value greater than or equal to 0
    */
    void setHealth(int newHealth);
    
    /*
    *sets a new positive x position
    */
    void setPosX(int newPosX);

    /*
    *sets a new positive y position
    */
    void setPosY(int newPosY);
    
    /*
    * sets a new entity id
    */
    void setEntityID(int newID);

    /*
    *sets the symbol to be rendered
    */
    void setSymbol(char newSymbol);

    /*
    *sets the name of the entity
    */
    void setEntityName(std::string newName);
    
    int getHealth() const;
    int getPosX() const;
    int getPosY() const;
    int getEntityID();
    char getSymbol() const;
    std::string getEntityName() const;
    
};
#endif
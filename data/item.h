#include <cstdlib>
#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item{

    public:
    Item(std::string newName = std::string("N/A"), int newId = 0, int newUses = 1);
    bool operator ==(Item other){
        return(id == other.id);
    }

    private:
    std::string name;
    int id;
    int uses;

};

#endif
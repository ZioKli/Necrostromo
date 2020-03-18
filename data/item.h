#include <cstdlib>
#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item{

    public:
    Item();
    bool operator ==(Item other){
        return(id == other.id);
    }

    private:
    std::string name;
    int id;
    int uses;

};

#endif
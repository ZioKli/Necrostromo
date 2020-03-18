
#include <vector>
#include "item.h"
#include "dependencies/dlist.h"
#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory{
    public:
    void setMaxSize(int newSize);
    void addItem(Item newItem);
    private: 
    int maxSize;
    dlist<Item> items;
};

#endif
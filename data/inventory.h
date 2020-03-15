
#include <vector>
#include "item.h"
#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory{
    public:
    void setMaxSize(int newSize);
    void addItem(Item newItem);
    private: 
    int maxSize;
    std::vector<Item> items;
};

#endif
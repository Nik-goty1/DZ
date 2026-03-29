#pragma once

#include "Actor.h"

class Item;

class DroppedItem : public Actor
{
public:
    Item* item;
    int quantity;

    DroppedItem(Item* item, int quantity) : Actor("DroppedItem", "DroppedItem")
    {
        this->item = item;
        this->quantity = quantity;
    }
};

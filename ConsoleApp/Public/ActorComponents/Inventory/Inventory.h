#pragma once

#include <string>

#include "ItemSlot.h"
#include "../ActorComponent.h"

class Inventory : public ActorComponent
{
    int maxSlots;
    ItemSlot* slots;

public:

    Inventory(Actor* owner, int size = 20);
    ~Inventory();

    bool addItem(Item* item, int quantity = 1) const;
    bool dropItem(const std::string& name, Item*& droppedItem, int quantity = 1) const;

    void showInventory() const;
};

#pragma once

#include <iostream>

#include "Actor.h"
#include "../ActorComponents/Inventory/Inventory.h"

class Scene;

class Character : public Actor
{
    Inventory inventory;
    Scene* scene;
    TransformComponent* transform;

public:
    Character(std::string name, Scene* scene);

    void showInventory();

    void dropItem(const std::string& name, int quantity = 1);
    void pickUpItem(const std::string& name);

    Inventory& getInventory()
    {
        return inventory;
    }

    void interactWithChest(const std::string& chestName);
};

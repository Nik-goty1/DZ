#pragma once
#include "Actor.h"
#include "../ActorComponents/Cords.h"
#include "../ActorComponents/Inventory/Inventory.h"

class Chest : public Actor {
public:
    TransformComponent* transform;
    Inventory inventory;

    Chest(std::string name, float x, float y) : Actor(name), inventory(this) {
        transform = new TransformComponent(x, y);
    }
};
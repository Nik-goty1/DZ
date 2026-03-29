#pragma once
#include "ActorComponent.h"
#include "../Structures/Vector.h"

class TransformComponent : public ActorComponent {
public:
    Vector Position;

    TransformComponent(float x = 0, float y = 0) : Position{ x, y } {}

    void SetPosition(float x, float y) {
        Position.X = x;
        Position.Y = y;
    }
};
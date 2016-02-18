#pragma once

#include "Collidable.h"
#include "GameData.h"

class SnakePart : public Collidable
{
    public: enum Directions { UP, DOWN, LEFT = 3, RIGHT = 4 };
    public: Directions movingDirection;

    public: SnakePart();
};

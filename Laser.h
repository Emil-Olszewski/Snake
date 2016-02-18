#pragma once

#include "Collidable.h"
#include "Generator.h"
#include "GameData.h"

class Laser : public Collidable
{
    public: enum PossibleDirectionsMove { UP, DOWN, LEFT, RIGHT };

    public: PossibleDirectionsMove direction;
    public: bool isMoving;
    public: bool canHurtPlayer;

    public: Laser();
    public: void setStartingPosition();
    public: void setSize();
    public: void resetColor();
    public: void safeLaser();
    public: void updatePosition();
    public: bool isOutsideScreen();
};

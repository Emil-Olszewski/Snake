#pragma once

#include "Collidable.h"

class CollisionChecker
{
    private: float xPositionC1;
    private: float yPositionC1;
    private: float xPositionC2;
    private: float yPositionC2;
    private: float widthC1;
    private: float heightC1;
    private: float widthC2;
    private: float heightC2;

    private: void updateObjectsPosition(Collidable &col1, Collidable &col2);
    public: bool isCollisionBetween(Collidable &col1, Collidable &col2);
};

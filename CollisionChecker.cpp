#include "CollisionChecker.h"

void CollisionChecker::updateObjectsPosition(Collidable &col1, Collidable &col2)
{
    xPositionC1 = col1.getPosition().x;
    yPositionC1 = col1.getPosition().y;
    xPositionC2 = col2.getPosition().x;
    yPositionC2 = col2.getPosition().y;
    widthC1 = col1.getSize().x;
    heightC1 = col1.getSize().y;
    widthC2 = col2.getSize().x;
    heightC2 = col2.getSize().y;
}

bool CollisionChecker::isCollisionBetween(Collidable &col1, Collidable &col2)
{
    updateObjectsPosition(col1,col2);

    if(xPositionC1+widthC1 > xPositionC2 && xPositionC1 < xPositionC2+widthC2
    && yPositionC1+heightC1 > yPositionC2 && yPositionC1 < yPositionC2+heightC2){
        return true;
    }
    else {
        return false;
    }
}

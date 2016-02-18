#include "Collidable.h"

sf::Vector2f Collidable::getPosition()
{
    return rect.getPosition();
}

sf::Vector2f Collidable::getSize()
{
    return rect.getSize();
}

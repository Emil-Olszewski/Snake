#include "SnakePart.h"

SnakePart::SnakePart()
{
    rect.setFillColor(sf::Color::Black);
    rect.setSize(sf::Vector2f(GameData::snakePartSize,GameData::snakePartSize));
    movingDirection = LEFT;
}

#pragma once

#include <SFML/Graphics.hpp>

class Collidable
{
    public: sf::RectangleShape rect;

    public: sf::Vector2f getPosition();
    public: sf::Vector2f getSize();
};

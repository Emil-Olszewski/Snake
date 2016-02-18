#pragma once

#include <SFML/Graphics.hpp>

#include "Collidable.h"
#include "Generator.h"
#include "GameData.h"

class Item : public Collidable, public sf::Drawable, sf::Transformable
{
    public: enum Type { GOOD, BAD };
    public: Type type;
    public: int addingLenght;

    public: Item();
    private: int randomType();
    private: int randomAddingLenght();
    private: sf::Vector2f randomPlace();;
    private: sf::Color randomColor();
    private: int randomColorNumber();

    public: virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

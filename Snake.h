#pragma once

#include <vector>
#include <cstdlib>
#include "GameData.h"
#include "SnakePart.h"
#include "CollisionChecker.h"

class Snake : public sf::Drawable, sf::Transformable
{
    public: Snake();

    public: int length;
    public: std::vector <SnakePart> parties;
    private: CollisionChecker collisionChecker;

    public: void updatePosition();
    public: void updateMovingDirections();
    public: void turn(SnakePart::Directions direction);
    private: bool canTurn(SnakePart::Directions direction);

    public: void modifySize(int numberToAddOrDelete);
    private: void addParts(int howMany);
    private: void deleteParts(int howMany);
    private: sf::Vector2f getValidPositionForNewPart();
    private: sf::Vector2f getCenterPosition();

    public: bool isCollidedWithItself();
    public: bool isOutsideScreen();

    public: virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


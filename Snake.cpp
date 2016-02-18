#include "Snake.h"

Snake::Snake()
{
    length = 0;
    modifySize(1);
}

void Snake::updatePosition()
{
    for(size_t i=0; i<parties.size(); i++)
    {
        switch(parties[i].movingDirection)
        {
            case SnakePart::UP: parties[i].rect.move(0,-GameData::snakePartSize); break;
            case SnakePart::DOWN: parties[i].rect.move(0,GameData::snakePartSize); break;
            case SnakePart::LEFT: parties[i].rect.move(-GameData::snakePartSize,0); break;
            case SnakePart::RIGHT: parties[i].rect.move(GameData::snakePartSize,0); break;
        }
    }
}

void Snake::updateMovingDirections()
{
    for(size_t i=parties.size()-1; i>0; i--)
    {
        parties[i].movingDirection = parties[i-1].movingDirection;
    }
}

void Snake::turn(SnakePart::Directions direction)
{
    if(canTurn(direction) && parties.size() > 0) parties[0].movingDirection = direction;
}

bool Snake::canTurn(SnakePart::Directions direction)
{
    if(parties.size() > 0){
        if(abs(direction - parties[0].movingDirection) >= 2) return true;
        else return false;
    }
    else {
        return false;
    }
}

void Snake::modifySize(int numberToAddOrDelete)
{
    length += numberToAddOrDelete;

    if(numberToAddOrDelete > 0) addParts(numberToAddOrDelete);
    else if(numberToAddOrDelete < 0) deleteParts(numberToAddOrDelete);
}

void Snake::addParts(int howMany)
{
    for(int i=0; i<howMany; i++)
    {
        parties.push_back(SnakePart());

        if(parties.size() > 1){
            parties[parties.size()-1].rect.setPosition(getValidPositionForNewPart());
            parties[parties.size()-1].movingDirection = parties[parties.size()-2].movingDirection;
        }
        else {
            parties[parties.size()-1].rect.setPosition(getCenterPosition());
        }
    }
}

void Snake::deleteParts(int howMany)
{
    for(int i=0; i<(howMany*-1); i++)
    {
        if(parties.size() > 0) parties.pop_back();
    }
}

sf::Vector2f Snake::getValidPositionForNewPart()
{
    sf::Vector2f vector2f;
    SnakePart *previousPart = &parties[parties.size()-2];

    switch(previousPart->movingDirection)
    {
        case SnakePart::UP:
            vector2f.x = previousPart->rect.getPosition().x;
            vector2f.y = previousPart->rect.getPosition().y + GameData::snakePartSize;
            break;

        case SnakePart::DOWN:
            vector2f.x = previousPart->rect.getPosition().x;
            vector2f.y = previousPart->rect.getPosition().y - GameData::snakePartSize;
            break;

        case SnakePart::LEFT:
            vector2f.x = previousPart->rect.getPosition().x + GameData::snakePartSize;
            vector2f.y = previousPart->rect.getPosition().y;
            break;

        case SnakePart::RIGHT:
            vector2f.x = previousPart->rect.getPosition().x - GameData::snakePartSize;
            vector2f.y = previousPart->rect.getPosition().y;
            break;
        }

    return vector2f;
}

sf::Vector2f Snake::getCenterPosition()
{
    sf::Vector2f vector2f;
	vector2f.x = GameData::windowWidth/2 - GameData::snakePartSize/2;
    vector2f.y = GameData::windowHeight/2 - GameData::snakePartSize/2;
    return vector2f;
}

bool Snake::isCollidedWithItself()
{
    for(size_t i=1; i<parties.size(); i++)
    {
        if(collisionChecker.isCollisionBetween(parties[0], parties[i])){
            return true;
        }
    }

    return false;
}

bool Snake::isOutsideScreen()
{
    if(parties.size() > 0){
        sf::RectangleShape *head = &parties[0].rect;

        if(head->getPosition().x > GameData::windowWidth || head->getPosition().x < 0){
            return true;
        }
        else if(head->getPosition().y > GameData::windowHeight || head->getPosition().y < 0){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(size_t i=0; i<parties.size(); i++)
    {
        target.draw(parties[i].rect);
    }
}

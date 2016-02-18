#include "Laser.h"

Laser::Laser()
{
    rect.setFillColor(sf::Color::Red);
    isMoving = false;
    canHurtPlayer = true;
}

void Laser::setStartingPosition()
{
    direction = PossibleDirectionsMove(Generator::getRandomNumber(0,3));
    int random = Generator::getRandomNumber(50,GameData::windowHeight-50);
    switch(direction)
    {
        case UP:
            rect.setPosition(random,GameData::windowHeight+5);
            break;

        case DOWN:
            rect.setPosition(random,-205);
            break;

        case LEFT:
            rect.setPosition(GameData::windowWidth+205,random);
            break;

        case RIGHT:
            rect.setPosition(-205,random);
            break;
    }

}

void Laser::setSize()
{
    switch(direction)
    {
        case UP:
            rect.setSize(sf::Vector2f(3,200));
            break;

        case DOWN:
            rect.setSize(sf::Vector2f(3,200));
            break;

        case LEFT:
            rect.setSize(sf::Vector2f(200,3));
            break;

        case RIGHT:
            rect.setSize(sf::Vector2f(200,3));
            break;
    }
}

void Laser::resetColor()
{
    rect.setFillColor(sf::Color::Red);
    canHurtPlayer = true;
}

void Laser::safeLaser()
{
    rect.setFillColor(sf::Color::Blue);
    canHurtPlayer = false;
}

void Laser::updatePosition()
{
    if(isMoving){
        switch(direction)
        {
            case UP: rect.move(0,-10); break;
            case DOWN: rect.move(0,10); break;
            case LEFT: rect.move(-10,0); break;
            case RIGHT: rect.move(10,0); break;
        }
    }
}

bool Laser::isOutsideScreen()
{
    switch(direction)
    {
        case UP:
            if(rect.getPosition().y + rect.getGlobalBounds().height < 0)
            return true; break;

        case DOWN:
            if(rect.getPosition().y - rect.getGlobalBounds().height > GameData::windowHeight)
            return true; break;

        case LEFT:
            if(rect.getPosition().x + rect.getGlobalBounds().width < 0)
            return true; break;

        case RIGHT:
            if(rect.getPosition().x - rect.getGlobalBounds().width > GameData::windowWidth)
            return true; break;

        default:
            return false;
    }

    return false;
}

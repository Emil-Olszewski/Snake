#include "Item.h"

Item::Item()
{
    type = Type(randomType());
    addingLenght = randomAddingLenght();
    rect.setFillColor(randomColor());
    rect.setPosition(randomPlace());
}

int Item::randomType()
{
    int random = Generator::getRandomNumber(0,15);
    if(random > 2){
        return 0;
    }
    else {
        return 1;
    }
}

int Item::randomAddingLenght()
{
    int randomAddingLenght = Generator::getRandomNumber(5,20);
    rect.setSize(sf::Vector2f(randomAddingLenght,randomAddingLenght));

    if(type == Type::BAD){
        return -randomAddingLenght;
    }
    else {
        return randomAddingLenght;
    }
}

sf::Vector2f Item::randomPlace()
{
    sf::Vector2f place;

    place.x = Generator::getRandomNumber(0,GameData::windowWidth-addingLenght);
    place.y = Generator::getRandomNumber(0,GameData::windowHeight-addingLenght);

    return place;
}

sf::Color Item::randomColor()
{
    int numberOfColor = randomColorNumber();
    switch(numberOfColor)
    {
        case 0: return sf::Color(0,0,0); break;
        case 1: return sf::Color(170,0,0); break;
        case 2: return sf::Color(61,63,64); break;
        case 3: return sf::Color(84,214,51); break;
        case 4: return sf::Color(243,156,255); break;
        case 5: return sf::Color(94,169,230); break;
    }
}

int Item::randomColorNumber()
{
    if(type == Type::BAD){
        return Generator::getRandomNumber(0,2);
    }
    else {
        return Generator::getRandomNumber(3,5);
    }
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect);
}

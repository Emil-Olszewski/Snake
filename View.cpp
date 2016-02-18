#include "View.h"

void View::setHeaderProperties()
{
    header.setString(headerText);
    header.setFont(font);
    header.setCharacterSize(90);
    header.setPosition(countCentre(header),50);
    header.setColor(sf::Color::Red);
}

void View::setOptionsProperties()
{
    for(int i=0; i<numberOfOptions; i++)
    {
        options[i].setFont(font);
        options[i].setString(optionsText[i]);
        options[i].setCharacterSize(60);
        options[i].setPosition(countCentre(options[i]), 2*50 + 90*(i+1));
        options[i].setColor(sf::Color::Black);
    }
}

float View::countCentre(sf::Text &text) const
{
    return GameData::windowWidth/2 - text.getGlobalBounds().width/2;
}

void View::setValidOptionsColor(sf::Vector2f &mouse) const
{
    for(int i=0; i<numberOfOptions; i++)
    {
        if(options[i].getGlobalBounds().contains(mouse)){
            options[i].setColor(sf::Color::Red);
        }
        else{
            options[i].setColor(sf::Color::Black);
        }
    }
}

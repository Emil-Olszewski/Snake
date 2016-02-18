#pragma once

#include <SFML/Graphics.hpp>
#include "GameData.h"
#include "GameInfo.h"

class View
{
    public: virtual void show() = 0;

    protected: sf::RenderWindow *window;
    protected: GameInfo *gameInfo;
    protected: sf::Font font;

    protected: sf::Text header;
    protected: std::string headerText;

    protected: int numberOfOptions;
    protected: sf::Text *options;
    protected: std::string *optionsText;

    protected: void setHeaderProperties();
    protected: void setOptionsProperties();
    protected: float countCentre(sf::Text &text) const;
    protected: void setValidOptionsColor(sf::Vector2f &mouse) const;
};

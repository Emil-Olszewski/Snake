#pragma once

#include "View.h"

class VMenu : View
{
    private: sf::Text author;
    public: VMenu(sf::RenderWindow &window, GameInfo &gameInfo, sf::Font font);
    public: ~VMenu();
    public: virtual void show();
    private: void setPrivateTextProperties();
};


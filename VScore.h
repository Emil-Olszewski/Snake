#pragma once

#include "View.h"
#include "Converter.h"

class VScore : View
{
    public: VScore(sf::RenderWindow &window, GameInfo &gameInfo, sf::Font font);
    public: ~VScore();
    public: virtual void show();
};



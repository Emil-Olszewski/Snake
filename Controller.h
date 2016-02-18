#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include "GameInfo.h"
#include "GameData.h"
#include "Game.h"
#include "VMenu.h"
#include "VScore.h"
#include "AudioController.h"

class Controller
{
    public: Controller();
    public: void run();

    private: sf::RenderWindow window;
    private: GameInfo gameInfo;
    private: sf::Font font;
    private: AudioController audioController;

    private: void loadFont();
    private: void runGame();
    private: void showMenuView();
    private: void showScoreView();
};


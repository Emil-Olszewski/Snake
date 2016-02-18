#pragma once

#include "SFML/Graphics.hpp"
#include "GameInfo.h"
#include "Interface.h"
#include "Snake.h"
#include "SnakePart.h"
#include "Item.h"
#include "Laser.h"
#include "CollisionChecker.h"
#include "AudioController.h"

class Game
{
    public: Game(sf::RenderWindow &window, GameInfo &gameInfo, sf::Font font);
    public: void run();

    private: sf::RenderWindow *window;
    private: GameInfo *gameInfo;
    private: sf::Font font;

    private: enum PossibleFrameTimes { NORMAL = 10, SLOW = 50 };
    private: PossibleFrameTimes frameTime;
    private: Interface interface;
    private: CollisionChecker collisionChecker;
    private: Snake snake;
    private: Laser laser;
    private: AudioController audioController;
    public: std::vector <Item> items;

    private: sf::Clock frameClock;
    private: sf::Time frameElapsedTime;
    private: sf::Time frameTimeToReach;
    private: void updateFrame();


    private: sf::Clock energyClock;
    private: sf::Time energyElapsedTime;
    private: sf::Time energyTimeToReach;
    private: void updateEnergy();
    private: float energy;


    private: sf::Clock itemClock;
    private: sf::Time itemElapsedTime;
    private: sf::Time itemTimeToReach;
    private: void updateItemsState();
    private: bool isTimeToGenerateItem();
    private: void generateItem();
    private: void deleteItemIfSnakeAteIt();
    private: void deleteItem(int itemNumber);

    private: static constexpr float ITEM_GENERATION_TIME = 3.0;

    private: sf::Clock laserClock;
    private: sf::Time laserElapsedTime;
    private: sf::Time laserTimeToReach;
    private: bool isLaserSet;
    private: void updateLaser();
    private: bool isTimeToShotLaser();
    private: void deleteSnakePartiesIfCollidedWithLaser();

    private: static constexpr float LASER_SHOT_TIME = 5;

    private: bool isGameNeedToEnd();
    private: int countScore();
};

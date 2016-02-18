#pragma once

#include <SFML/Graphics.hpp>
#include "Converter.h"
#include "GameData.h"

class Interface : public sf::Drawable, sf::Transformable
{
    private: sf::Font font;

    private: sf::Text scoreText;
    private: sf::Text scoreNumber;
    private: int numberOfNumberInScoreDuringPreviousTextPositionChange;
    private: int score;

    private: sf::RectangleShape energyRect;
    private: sf::RectangleShape energyOutline;
    private: float energy;
    private: int timeToLaserShot;

    private: sf::Text timeText;

    public: void setProperties();
    public: void setFont(sf::Font font);

    public: void update();
    public: void updateScore(int score);
    public: void updateEnergy(int energy);
    public: void updateTimeToLaserShot(int time);

    private: void setTextPosition();
    private: bool isNeedTextToUpdatePosition();
    int getNumberOfNumbersIn(int number);

    public: virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

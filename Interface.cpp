#include "Interface.h"

void Interface::setProperties()
{
    scoreText.setFont(font);
    scoreText.setString("SCORE:");
    scoreText.setColor(sf::Color::Black);
    scoreText.setCharacterSize(40);

    scoreNumber.setFont(font);
    scoreNumber.setString("0");
    scoreNumber.setColor(sf::Color::Red);
    scoreNumber.setCharacterSize(40);

    numberOfNumberInScoreDuringPreviousTextPositionChange = 0;

    energyRect.setPosition(20,570);
    energyRect.setSize(sf::Vector2f(energy,5));
    energyRect.setFillColor(sf::Color(75,245,40));

    energyOutline.setPosition(20,570);
    energyOutline.setSize(sf::Vector2f(GameData::energyLimit,5));
    energyOutline.setFillColor(sf::Color(50,165,30));
    energyOutline.setOutlineThickness(1);
    energyOutline.setOutlineColor(sf::Color::Black);

    timeText.setFont(font);
    timeText.setString("0");
    timeText.setColor(sf::Color::Black);
    timeText.setCharacterSize(35);
    timeText.setPosition(GameData::windowWidth-50,GameData::windowHeight-50);
}

void Interface::setFont(sf::Font font)
{
    this->font = font;
}

void Interface::update()
{
    scoreNumber.setString(Converter::convertIntToString(score));
    energyRect.setSize(sf::Vector2f(energy,5));
    timeText.setString(Converter::convertIntToString(timeToLaserShot));

    if(isNeedTextToUpdatePosition()){
        setTextPosition();
    }
}

void Interface::updateScore(int score)
{
    this->score = score;
}

void Interface::updateEnergy(int energy)
{
    this->energy = energy;
}

void Interface::updateTimeToLaserShot(int time)
{
    this->timeToLaserShot = time;
}

void Interface::setTextPosition()
{
    int textWidth = scoreText.getGlobalBounds().width + scoreNumber.getGlobalBounds().width + 10;
    scoreText.setPosition((GameData::windowWidth - textWidth)/2, 20);

    int scorePositionX = scoreText.getPosition().x + scoreText.getGlobalBounds().width + 20;
    scoreNumber.setPosition(scorePositionX, 20);
}

bool Interface::isNeedTextToUpdatePosition()
{
    int numberOfNumbersInScore = getNumberOfNumbersIn(score);
    if(numberOfNumbersInScore > numberOfNumberInScoreDuringPreviousTextPositionChange){
        numberOfNumberInScoreDuringPreviousTextPositionChange = numberOfNumbersInScore;
        return true;
    }
    else {
        return false;
    }
}

int Interface::getNumberOfNumbersIn(int number)
{
    int numberOfNumbers = 1;
    for(float i=10; i>0; i*=10)
    {
        if(number / i >= 1) numberOfNumbers++;
        else break;
    }

    return numberOfNumbers;
}

void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(scoreText);
    target.draw(scoreNumber);
    target.draw(energyOutline);
    target.draw(energyRect);
    target.draw(timeText);
}

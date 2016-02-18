#include "VScore.h"

VScore::VScore(sf::RenderWindow &window, GameInfo &gameInfo, sf::Font font)
{
    this->window = &window;
    this->gameInfo = &gameInfo;
    this->font = font;

    std::string score = Converter::convertIntToString(gameInfo.score);
    std::string text = "YOUR SCORE: ";
    headerText = text + score;

    numberOfOptions = 2;
    options = new sf::Text[numberOfOptions];
    optionsText = new std::string[numberOfOptions];
    optionsText[0] = "TRY AGAIN";
    optionsText[1] = "RETURN TO MENU";

    setHeaderProperties();
    setOptionsProperties();
}

VScore::~VScore()
{
    delete[] options;
    delete[] optionsText;
}

void VScore::show()
{
    while(gameInfo->state == GameInfo::SCORE)
    {
        sf::Vector2f mouse(sf::Mouse::getPosition(*window));
        sf::Event event;

        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape
            || event.type == sf::Event::Closed){
                gameInfo->state = GameInfo::END;
            }

            if(event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left){
                if(options[0].getGlobalBounds().contains(mouse)){
                    gameInfo->state = GameInfo::GAME;
                }
                else if(options[1].getGlobalBounds().contains(mouse)){
                    gameInfo->state = GameInfo::MENU;
                }
            }
        }

        setValidOptionsColor(mouse);

        window->clear(sf::Color::White);
        window->draw(header);

        for(int i=0; i<numberOfOptions; i++)
        {
            window->draw(options[i]);
        }

        window->display();
    }
}

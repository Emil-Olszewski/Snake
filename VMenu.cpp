#include "VMenu.h"

VMenu::VMenu(sf::RenderWindow &window, GameInfo &gameInfo, sf::Font font)
{
    this->window = &window;
    this->gameInfo = &gameInfo;
    this->font = font;

    headerText = GameData::gameName;

    numberOfOptions = 2;
    options = new sf::Text[numberOfOptions];
    optionsText = new std::string[numberOfOptions];
    optionsText[0] = "PLAY";
    optionsText[1] = "EXIT";

    setHeaderProperties();
    setOptionsProperties();
    setPrivateTextProperties();
}

VMenu::~VMenu()
{
    delete[] options;
    delete[] optionsText;
}

void VMenu::show()
{
    while(gameInfo->state == GameInfo::MENU)
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
                    gameInfo->state = GameInfo::END;
                }
            }
        }

        setValidOptionsColor(mouse);

        window->clear(sf::Color::White);
        window->draw(header);
        window->draw(author);

        for(int i=0; i<numberOfOptions; i++)
        {
            window->draw(options[i]);
        }

        window->display();
    }
}

void VMenu::setPrivateTextProperties()
{
    author.setFont(font);
    author.setColor(sf::Color::Red);
    author.setCharacterSize(20);
    author.setPosition(20, GameData::windowHeight-30);
    author.setString("Emil Olszewski 2016");
}

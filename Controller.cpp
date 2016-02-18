#include "Controller.h"

Controller::Controller()
{
    window.create(sf::VideoMode(GameData::windowWidth,GameData::windowHeight),GameData::gameName);
    loadFont();

    srand(time(NULL));
}

void Controller::loadFont()
{
    font.loadFromFile("data/Mecha.ttf");
}

void Controller::run()
{
    while(window.isOpen())
    {
        switch(gameInfo.state)
        {
            case GameInfo::GAME:
                runGame();
                break;

            case GameInfo::MENU:
                showMenuView();
                break;

            case GameInfo::SCORE:
                showScoreView();
                break;

            case GameInfo::END:
                window.close();
                break;
        }
    }
}

void Controller::runGame()
{
    Game game(window, gameInfo, font);
    audioController.play(AudioController::MUS2);
    game.run();
}

void Controller::showMenuView()
{
    VMenu vMenu(window, gameInfo, font);
    audioController.play(AudioController::MUS1);
    vMenu.show();
}

void Controller::showScoreView()
{
    VScore vScore(window, gameInfo, font);
    audioController.play(AudioController::MUS1);
    vScore.show();
}

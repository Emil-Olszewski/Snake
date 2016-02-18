#include "Game.h"
#include <iostream>
Game::Game(sf::RenderWindow &window, GameInfo &gameInfo, sf::Font font)
{
    this->window = &window;
    this->gameInfo = &gameInfo;
    this->font = font;

    frameTime = NORMAL;

    interface.setFont(font);
    interface.setProperties();
    energy = GameData::energyLimit;
    isLaserSet = false;
}

void Game::run()
{
    while(gameInfo->state == GameInfo::GAME)
    {
        sf::Event event;
        while(window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                gameInfo->state = GameInfo::END;
            }

            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        gameInfo->state = GameInfo::MENU;
                        break;

                    case sf::Keyboard::W:
                    case sf::Keyboard::Up:
                        snake.turn(SnakePart::UP);
                        break;

                    case sf::Keyboard::S:
                    case sf::Keyboard::Down:
                        snake.turn(SnakePart::DOWN);
                        break;

                    case sf::Keyboard::A:
                    case sf::Keyboard::Left:
                        snake.turn(SnakePart::LEFT);
                        break;

                    case sf::Keyboard::D:
                    case sf::Keyboard::Right:
                        snake.turn(SnakePart::RIGHT);
                        break;

                    case sf::Keyboard::Space:
                        if(frameTime == NORMAL){
                            frameTime = SLOW;
                            audioController.play(AudioController::SPD_DOWN);
                        }
                        else {
                            frameTime = NORMAL;
                            audioController.play(AudioController::SPD_UP);
                        }
                        break;

                    case sf::Keyboard::B:
                        snake.modifySize(10);
                        break;
                }
            }
        }

        updateFrame();
        updateEnergy();
        updateItemsState();
        updateLaser();

        sf::Vector2f mouse(sf::Mouse::getPosition(*window));
        if(laser.rect.getGlobalBounds().contains(mouse)){
            laser.safeLaser();
        }

        if(isGameNeedToEnd()){
            gameInfo->state = GameInfo::SCORE;
        }

        gameInfo->score = countScore();
        interface.updateScore(gameInfo->score);
        interface.updateEnergy(energy);
        interface.updateTimeToLaserShot(int(LASER_SHOT_TIME + 1 - laserClock.getElapsedTime().asSeconds()));
        interface.update();

        window->clear(sf::Color::White);
        window->draw(interface);
        window->draw(snake);
        window->draw(laser.rect);

        for(size_t i=0; i<items.size(); i++)
        {
            window->draw(items[i]);
        }

        window->display();
    }
}

void Game::updateFrame()
{
    frameElapsedTime = frameClock.getElapsedTime();
    frameTimeToReach = sf::milliseconds(frameTime);

    if(frameElapsedTime > frameTimeToReach){
        frameClock.restart();
        snake.updatePosition();
        snake.updateMovingDirections();
        laser.updatePosition();
    }
}

void Game::updateEnergy()
{
    energyTimeToReach = sf::seconds(0.02);
    energyElapsedTime= energyClock.getElapsedTime();

    if(energyElapsedTime > energyTimeToReach){
        if(frameTime == NORMAL){
            if(energy < GameData::energyLimit) energy += 0.5;
        }
        if(frameTime == SLOW) {
            if(energy > 0) energy -= 1.5;
        }

        energyClock.restart();
    }

    if(energy <= 0){
        audioController.play(AudioController::SPD_UP);
        frameTime = NORMAL;
    }

    if(energy < 0) energy = 0;
    if(energy > GameData::energyLimit) energy = GameData::energyLimit;
}

void Game::updateItemsState()
{
    if(isTimeToGenerateItem()) generateItem();
    deleteItemIfSnakeAteIt();
}

bool Game::isTimeToGenerateItem()
{
    itemTimeToReach = sf::seconds(ITEM_GENERATION_TIME);
    itemElapsedTime = itemClock.getElapsedTime();

    if(itemElapsedTime > itemTimeToReach){
        itemClock.restart();
        return true;
    }
}

void Game::generateItem()
{
    if(items.size() == 10) items.erase(items.begin());
    if(items.size() < 10) items.push_back(Item());
}

void Game::deleteItemIfSnakeAteIt()
{
    for(size_t i=0; i<items.size(); i++)
    {
        if(collisionChecker.isCollisionBetween(snake.parties[0],items[i])){
            if(items[i].addingLenght + snake.length > 0){
                snake.modifySize(items[i].addingLenght);
            }
            else {
                snake.modifySize(snake.length * -1);
            }

            deleteItem(i);
        }
    }
}

void Game::deleteItem(int itemNumber)
{
    items.erase(items.begin() + itemNumber);
}

void Game::updateLaser()
{
    if(isLaserSet == false){
        laser.setStartingPosition();
        laser.setSize();
        laser.resetColor();
        isLaserSet = true;
    }

    if(isTimeToShotLaser()){
        laser.isMoving = true;
        audioController.play(AudioController::LASER_SHT);
    }

    if(laser.isMoving){
        deleteSnakePartiesIfCollidedWithLaser();
        if(laser.isOutsideScreen()){
            laser.isMoving = false;
            isLaserSet = false;
        }
    }
}

bool Game::isTimeToShotLaser()
{
    laserTimeToReach = sf::seconds(LASER_SHOT_TIME);
    laserElapsedTime = laserClock.getElapsedTime();

    if(laserElapsedTime > laserTimeToReach){
        laserClock.restart();
        return true;
    }
    else {
        return false;
    }
}

void Game::deleteSnakePartiesIfCollidedWithLaser()
{
    if(laser.canHurtPlayer){
        for(size_t i=0; i<snake.parties.size(); i++)
        {
            if(collisionChecker.isCollisionBetween(laser, snake.parties[i])){
                snake.modifySize(-1 * (snake.parties.size()-i-1));
            }
        }
    }
}

bool Game::isGameNeedToEnd()
{
    if(snake.isCollidedWithItself() || snake.isOutsideScreen() || snake.length <= 0){
        return true;
    }
    else {
        return false;
    }
}

int Game::countScore()
{
    return snake.length * 3;
}

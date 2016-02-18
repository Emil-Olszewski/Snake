#include "AudioController.h"

AudioController::AudioController()
{
    soundBuffer1.loadFromFile("data/slowDown");
    soundBuffer2.loadFromFile("data/speedUp");
    soundBuffer3.loadFromFile("data/laserShot");
    music1.openFromFile("data/menuMusic");
    music2.openFromFile("data/gameMusic");

    music1.setLoop(true);
    music2.setLoop(true);
}

void AudioController::play(Sounds whatToPlay)
{
    switch(whatToPlay)
    {
        case SPD_DOWN:
            sound1.setBuffer(soundBuffer1);
            sound1.play();
            break;

        case SPD_UP:
            sound1.setBuffer(soundBuffer2);
            sound1.play();
            break;

        case LASER_SHT:
            sound2.setBuffer(soundBuffer3);
            sound2.play();
            break;

        case MUS1:
            if(music2.getStatus() == sf::SoundSource::Status::Playing){
                music2.stop();
            }

            if(music1.getStatus() == sf::SoundSource::Status::Stopped){
            music1.play();
            }

            break;

        case MUS2:
            music1.stop();
            music2.play();
            break;
    }
}

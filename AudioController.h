#pragma once

#include <SFML/Audio.hpp>


class AudioController
{
    public: sf::SoundBuffer soundBuffer1;
    public: sf::SoundBuffer soundBuffer2;
    public: sf::SoundBuffer soundBuffer3;

    public: sf::Sound sound1;
    public: sf::Sound sound2;

    public: sf::Music music1;
    public: sf::Music music2;

    public: enum Sounds { SPD_DOWN, SPD_UP, LASER_SHT, MUS1, MUS2 };

    public: AudioController();
    public: void play(Sounds whatToPlay);
};

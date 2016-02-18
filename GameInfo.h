#pragma once

class GameInfo
{
    public: enum PossibleGameStates { GAME, MENU, SCORE, HELP, END };
    public: PossibleGameStates state;
    public: int score;

    public: GameInfo();
};

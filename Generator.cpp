#include "Generator.h"

int Generator::getRandomNumber(int from, int to)
{
    return rand()%(to-from+1)+from;
}


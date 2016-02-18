#include "Converter.h"

std::string Converter::convertIntToString(int number)
{
    std::ostringstream converter;
    converter << number;
    std::string text = converter.str();
    return text;
}

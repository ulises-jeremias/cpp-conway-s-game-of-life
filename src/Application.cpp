#include <iostream>
#include <random>
#include <ctime>

#include "Application.h"

namespace
{
sf::Color deadColour   = sf::Color::White;
sf::Color aliveColour  = sf::Color::Black;
}

sf::Color& getCellColour(Cell cell)
{
        return cell == Cell::Alive ?
               aliveColour :
               deadColour;
}

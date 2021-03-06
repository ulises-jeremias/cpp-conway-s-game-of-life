#include <iostream>

#include "Application.hpp"
#include "Config.hpp"

using namespace std;

/**
 * Rules:
 * The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells,
 * each of which is in one of two possible states, alive or dead, or "populated" or "unpopulated".
 * Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or
 * diagonally adjacent. At each step in time, the following transitions occur:
 *
 *  --| Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
 *  --| Any live cell with two or three live neighbours lives on to the next generation.
 *  --| Any live cell with more than three live neighbours dies, as if by overpopulation.
 *  --| Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
 */

int main()
{
        Config config;

        char option;
        cout << "Would you like to use default config? [Y/N]: ";
        cin >> option;
        option = toupper(option);

        if (option == 'N')
        {
                cout << "Enter window width: ";
                cin >> config.windowWidth;

                cout << "Enter window height: ";
                cin >> config.windowHeight;

                cout << "Enter cell size: ";
                cin >> config.quadSize;

                //Make it so that the cells fit in the window
                config.windowWidth -= config.windowWidth   % config.quadSize;
                config.windowHeight -= config.windowHeight % config.quadSize;

                config.simWidth  =  config.windowWidth  / config.quadSize;
                config.simHeight =  config.windowHeight / config.quadSize;
        }
        else
        {
                config.quadSize     = 8;
                config.windowWidth  = 1024;
                config.windowHeight = 768;

                config.simWidth     =  config.windowWidth  / config.quadSize;
                config.simHeight    =  config.windowHeight / config.quadSize;
        }

        Application app(config);
        app.run();
}

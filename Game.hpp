/*********************************************************************
** Program name: Game.hpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: 
** 
** 
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Grid.hpp"

#include "Menu.hpp"

class Game
{
private:
    int step;
    Menu continueMenu;
    Grid* grid;
    void initializeGrid();
    void takeStep();
public:
    Game();
    void run();
};

#endif
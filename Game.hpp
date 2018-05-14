/*********************************************************************
** Program name: Game.hpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: Specification for the Game class, the interface for
** running the Ants & Doodlebugs simulation.  Call run() to
** start the simulation. Implementation in Game.cpp.
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
	Grid *grid;
	void initializeGrid();
	void takeStep();
public:
	Game();
	~Game();
	void run();
};

#endif
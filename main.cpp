/*********************************************************************
** Program name: Ants & Doodlebugs
** Author: Group 1 - CS162 Spring 2018
** Date: May 11, 2018
** Description: Predator and Prey simulation between ants and doodlebugs
** living on a 2D grid.  Users may choose the size of the grid and number
** of ants and doodlebugs at the start of simulation.
*********************************************************************/

#include "Game.hpp"

#include <ctime> // time()
#include <cstdlib> // srand()

int main()
{
	// seed rand in main to avoid reseeding
	srand(time(0));

	Game game;
	game.run();

	return 0;
}
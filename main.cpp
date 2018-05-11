/*********************************************************************
** Program name: Ants & Doodlebugs
** Author: Group 1 - CS162 Spring 2018
** Date: May 11, 2018
** Description: 
** 
** 
*********************************************************************/

#include "Game.hpp"

#include <ctime>
#include <cstdlib>

int main()
{
	// seed rand in main to avoid reseeding
	srand(time(0));

	Game game;
	game.run();

	return 0;
}
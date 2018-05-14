/*********************************************************************
** Program name: Game.cpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: Implementation of the Game class, the interface for
** running the Ants & Doodlebugs simulation.  Call run() to
** start the simulation. 
*********************************************************************/

#include "Game.hpp"

// critter class specifications
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

#include "helpers.hpp"
#include <iostream>
#include <climits> // INT_MAX

/*********************************************************************
** Default constructor. Initialize step and menu items.
*********************************************************************/
Game::Game()
{
	step = 1;
	grid = nullptr;

	continueMenu.setTitle("Game Over");
	continueMenu.addItem(1, "Continue running simulation");
	continueMenu.addItem(2, "Exit program");
}

/*********************************************************************
** Destructor for Game class. Deallocates memory from grid.
*********************************************************************/
Game::~Game()
{
	if (grid != nullptr)
	{
		delete grid;
	}
}

/*********************************************************************
** run: The public interface for running an instance of the Ants & Doodlebugs
** simulation. Call from main() to run the simulation.
*********************************************************************/
void Game::run()
{
	std::cout << "|---------------------------------|" << std::endl;
	std::cout << "|  WELCOME TO DOODLEBUGS & ANTS   |" << std::endl;
	std::cout << "|           By Group 1            |" << std::endl;
	std::cout << "|        CS162 Spring 2018        |" << std::endl;
	std::cout << "|---------------------------------|" << std::endl
			  << std::endl;

	std::cout << "This program implements the extra credit option." << std::endl
			  << std::endl;

	initializeGrid();
	std::cout << "Initial board state" << std::endl;
	grid->print();

	// game loop
	do
	{
		std::cout << "Run simulation for how many time steps?" << std::endl;
		int steps = getInt(1, INT_MAX - step); // minimum 1 step. total steps shouldn't exceed INT_MAX
		std::cout << std::endl;
		pause();

		for (int i = 0; i < steps; i++)
		{
			takeStep();
		}

		if (step == INT_MAX)
		{
			// protect against step overflowing. don't allow continue after INT_MAX steps
			std::cout << "You have reached the maximum number of steps." << std::endl;
		}
		else
		{
			// allow user to continue if they desire
			continueMenu.print();
		}
	} while (continueMenu.getChoice() == 1 && step != INT_MAX);

	std::cout << "Goodbye!" << std::endl;
}

/*********************************************************************
** initializeGrid: Private function which initializes the grid after
** asking the user for the grid size and number of critters. After the
** grid is allocated, it places all ants and doodlebugs in random positions
** on the grid.
*********************************************************************/
void Game::initializeGrid()
{
	std::cout << "Let's start by setting up the grid." << std::endl;
	std::cout << "How many rows?" << std::endl;
	int rows = getInt(20, 200);
	std::cout << "How many columns?" << std::endl;
	int cols = getInt(20, 200);
	std::cout << "How many ants?" << std::endl;
	int numAnts = getInt(1, (rows * cols) - 1);
	std::cout << "How many doodlebugs?" << std::endl;
	int numDoodlebugs = getInt(1, (rows * cols) - numAnts);
	std::cout << std::endl;

	// create grid based on user input
	grid = new Grid(rows, cols);

	// create and place ants
	for (int i = 0; i < numAnts; i++)
	{
		// get random empty spot on grid for ant
		bool foundSpot = false;
		int randRow, randCol;
		while (!foundSpot)
		{
			randRow = getRandom(0, (grid->getRows() - 1));
			randCol = getRandom(0, (grid->getCols() - 1));
			if (grid->checkEmpty(randRow, randCol))
			{
				foundSpot = true;
			}
		}

		Ant *ant = new Ant(grid, randRow, randCol);
		grid->getGrid()[randRow][randCol] = ant;
	}

	// create and place doodlebugs!
	for (int i = 0; i < numDoodlebugs; i++)
	{
		// get random empty spot on grid for doodlebug
		bool foundSpot = false;
		int randRow, randCol;
		while (!foundSpot)
		{
			randRow = getRandom(0, (grid->getRows() - 1));
			randCol = getRandom(0, (grid->getCols() - 1));
			if (grid->checkEmpty(randRow, randCol))
			{
				foundSpot = true;
			}
		}

		Doodlebug *doodlebug = new Doodlebug(grid, randRow, randCol);
		grid->getGrid()[randRow][randCol] = doodlebug;
	}

	std::cout << "Initialized " << rows << "x" << cols << " grid with " << numAnts << " ants and " << numDoodlebugs << " doodlebugs." << std::endl;
	std::cout << std::endl;
}

/*********************************************************************
** takeStep: Private function which executes all parts of a single step
** in the simulation. Moves and breeds all critters, starves doodlebugs
** as necessary, prints board at the end of the step, and increments
** the step variable.
*********************************************************************/
void Game::takeStep()
{
	// set all critters as unmoved
	for (int row = 0; row < grid->getRows(); row++)
	{
		for (int col = 0; col < grid->getCols(); col++)
		{
			if (grid->getGrid()[row][col] != nullptr)
			{
				grid->getGrid()[row][col]->setMoved(false);
			}
		}
	}

	// move all doodlebugs first
	for (int row = 0; row < grid->getRows(); row++)
	{
		for (int col = 0; col < grid->getCols(); col++)
		{
			if (grid->getGrid()[row][col] != nullptr && grid->getGrid()[row][col]->getType() == DOODLEBUG)
			{
				if (grid->getGrid()[row][col]->getMoved() == false)
				{
					grid->getGrid()[row][col]->move();
				}
			}
		}
	}

	// move all ants
	for (int row = 0; row < grid->getRows(); row++)
	{
		for (int col = 0; col < grid->getCols(); col++)
		{
			if (grid->getGrid()[row][col] != nullptr && grid->getGrid()[row][col]->getType() == ANT)
			{
				if (grid->getGrid()[row][col]->getMoved() == false)
				{
					grid->getGrid()[row][col]->move();
				}
			}
		}
	}

	// breed all critters, starve doodlebugs, and age all surviving critters
	for (int row = 0; row < grid->getRows(); row++)
	{
		for (int col = 0; col < grid->getCols(); col++)
		{
			if (grid->getGrid()[row][col] != nullptr)
			{
				grid->getGrid()[row][col]->breed();

				// starve doodlebugs that have not eaten in 3 days
				if (grid->getGrid()[row][col]->getType() == DOODLEBUG)
				{
					if (dynamic_cast<Doodlebug *>(grid->getGrid()[row][col])->getDaysSinceEating() >= 3)
					{
						delete grid->getGrid()[row][col];
						grid->getGrid()[row][col] = nullptr;
					}
				}

				// age critter one day if it didn't already starve.
				if (grid->getGrid()[row][col] != nullptr)
				{
					grid->getGrid()[row][col]->age();
				}
			}
		}
	}

	// print board at end of step
	std::cout << "Step " << step << std::endl;
	grid->print();

	step++;
}
/*********************************************************************
** Program name: Critter.cpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 8, 2018
** Description: 
** 
** 
*********************************************************************/

#include "Critter.hpp" // Critter class specification
#include "Grid.hpp"	// Grid class specification

#include <iostream>

#include "helpers.hpp"

/*********************************************************************
** Default constructor for Critter
*********************************************************************/
Critter::Critter()
{
	stepsSurvived = 0;
	currentRow = currentCol = -1;
	grid = nullptr;
}

/*********************************************************************
** Constructor for Critter which takes integer parameters representing
** the row position and column position of the ant on the grid. 
*********************************************************************/
Critter::Critter(Grid *grid, int currentRow, int currentCol)
{
	stepsSurvived = 0;
	this->grid = grid;
	this->currentRow = currentRow;
	this->currentCol = currentCol;
}

/*********************************************************************
** Virtual Destructor for Critter class
*********************************************************************/
Critter::~Critter()
{
}

int Critter::getRowPosition() const
{
	return currentRow;
}

/*********************************************************************
** setRowPosition: Allows manual setting of row position if Critter
** was created with default constructor. Checks that row is valid within
** bounds of the grid. Returns true if successful, false otherwise.
*********************************************************************/
bool Critter::setRowPosition(int currentRow)
{
	// only allow setting row position manually if it was never set
	if (this->currentRow == -1 && currentRow >= 0)
	{
		// row must be in bounds of grid
		if (currentRow < grid->getRows() - 1)
		{
			this->currentRow = currentRow;
			return true;
		}
	}

	return false; // couldn't set row position
}

int Critter::getColPosition() const
{
	return currentCol;
}

/*********************************************************************
** setRowPosition: Allows manual setting of col position if Critter
** was created with default constructor. Checks that col is valid within
** bounds of the grid. Returns true if successful, false otherwise.
*********************************************************************/
bool Critter::setColPosition(int currentCol)
{
	// only allow setting col position manually if it was never set
	if (this->currentCol == -1 && currentCol >= 0)
	{
		// col must be in bounds of grid
		if (currentCol < grid->getCols() - 1)
		{
			this->currentCol = currentCol;
			return true;
		}
	}

	return false; // couldn't set col position
}

Grid *Critter::getGrid()
{
	return grid;
}

void Critter::setGrid(Grid *grid)
{
	this->grid = grid;
}

int Critter::getStepsSurvived() const
{
	return stepsSurvived;
}

/*********************************************************************
** move: 
** 
*********************************************************************/
void Critter::move() 
{
	Direction moveDirection = static_cast<Direction>(getRandom(0, 3));

	if (moveDirection == NORTH)
	{
		int destinationRow = currentRow - 1;

		// move only if space is empty and within grid bounds
		if (destinationRow >= 0 && grid->checkEmpty(destinationRow, currentCol))
		{
			Critter ***gridArray = grid->getGrid();
			gridArray[destinationRow][currentCol] = gridArray[currentRow][currentCol];
			gridArray[currentRow][currentCol] = nullptr;

			currentRow = destinationRow;
		}
	}
	else if (moveDirection == SOUTH)
	{
		int destinationRow = currentRow + 1;

		// move only if space is empty and within grid bounds
		if ((destinationRow < grid->getRows()) && grid->checkEmpty(destinationRow, currentCol))
		{
			Critter ***gridArray = grid->getGrid();
			gridArray[destinationRow][currentCol] = gridArray[currentRow][currentCol];
			gridArray[currentRow][currentCol] = nullptr;

			currentRow = destinationRow;
		}
	}
	else if (moveDirection == EAST)
	{
		int destinationCol = currentCol + 1;

		// move only if space is empty and within grid bounds
		if ((destinationCol < grid->getCols()) && grid->checkEmpty(currentRow, destinationCol))
		{
			Critter ***gridArray = grid->getGrid();
			gridArray[currentRow][destinationCol] = gridArray[currentRow][currentCol];
			gridArray[currentRow][currentCol] = nullptr;

			currentCol = destinationCol;
		}
	}
	else if (moveDirection == WEST)
	{
		int destinationCol = currentCol - 1;

		// move only if space is empty and within grid bounds
		if (destinationCol >= 0 && grid->checkEmpty(currentRow, destinationCol))
		{
			Critter ***gridArray = grid->getGrid();
			gridArray[currentRow][destinationCol] = gridArray[currentRow][currentCol];
			gridArray[currentRow][currentCol] = nullptr;

			currentCol = destinationCol;
		}
	}
}



/*********************************************************************
** breed: 
** 
*********************************************************************/
void Critter::breed(std::vector<Critter*>)
{
	// todo?
}

/*********************************************************************
** age: Critter survives one more step and stepsSurvived is incremented.
*********************************************************************/
void Critter::age()
{
	stepsSurvived++;
}

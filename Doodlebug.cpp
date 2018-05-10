/*********************************************************************
** Program name: Doodlebug.cpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: 
** 
** 
*********************************************************************/

#include "Doodlebug.hpp"
#include "Grid.hpp"
#include "helpers.hpp"

Doodlebug::Doodlebug() : Critter()
{
	daysSinceEating = 0;
}

Doodlebug::Doodlebug(Grid *grid, int currentRow, int currentCol) : Critter(grid, currentRow, currentCol)
{
	daysSinceEating = 0;
}

int Doodlebug::getDaysSinceEating()
{
	return daysSinceEating;
}

/*********************************************************************
** move: 
** 
*********************************************************************/
void Doodlebug::move()
{
	// check if any destination cells have ants
	if ( (currentRow - 1 >= 0 && grid->checkAnt(currentRow - 1, currentCol)) ||
		((currentRow + 1 < grid->getRows()) && grid->checkAnt(currentRow + 1, currentCol)) ||
		((currentCol + 1 < grid->getCols()) && grid->checkAnt(currentRow, currentCol + 1)) ||
		(currentCol - 1 >= 0 && grid->checkAnt(currentRow, currentCol - 1)) )
	{
		bool ateAnt = false;
		while (!ateAnt)
		{
			Direction moveDirection = static_cast<Direction>(getRandom(0, 3));

			if (moveDirection == NORTH)
			{
				int destinationRow = currentRow - 1;
				// move only if space is ANT and within grid bounds
				if (destinationRow >= 0 && grid->checkAnt(destinationRow, currentCol))
				{
					// delete the ant
					delete grid->getGrid()[destinationRow][currentCol];

					// move doodlebug and set old space to null
					grid->getGrid()[destinationRow][currentCol] = grid->getGrid()[currentRow][currentCol];
					grid->getGrid()[currentRow][currentCol] = nullptr;
					currentRow = destinationRow;

					this->daysSinceEating = 0;
					ateAnt = true;
				}
			}
			else if (moveDirection == SOUTH)
			{
				int destinationRow = currentRow + 1;
				if ((destinationRow < grid->getRows()) && grid->checkAnt(destinationRow, currentCol))
				{
					// delete the ant
					delete grid->getGrid()[destinationRow][currentCol];

					// move doodlebug and set old space to null
					grid->getGrid()[destinationRow][currentCol] = grid->getGrid()[currentRow][currentCol];
					grid->getGrid()[currentRow][currentCol] = nullptr;
					currentRow = destinationRow;

					this->daysSinceEating = 0;
					ateAnt = true;
				}
			}
			else if (moveDirection == EAST)
			{
				int destinationCol = currentCol + 1;
				if ((destinationCol < grid->getCols()) && grid->checkAnt(currentRow, destinationCol))
				{
					// delete the ant
					delete grid->getGrid()[currentRow][destinationCol];

					// move doodlebug and set old space to null
					grid->getGrid()[currentRow][destinationCol] = grid->getGrid()[currentRow][currentCol];
					grid->getGrid()[currentRow][currentCol] = nullptr;
					currentCol = destinationCol;

					this->daysSinceEating = 0;
					ateAnt = true;
				}
			}
			else if (moveDirection == WEST)
			{
				int destinationCol = currentCol - 1;

				if (destinationCol >= 0 && grid->checkAnt(currentRow, destinationCol))
				{
					// delete the ant
					delete grid->getGrid()[currentRow][destinationCol];

					// move doodlebug and set old space to null
					grid->getGrid()[currentRow][destinationCol] = grid->getGrid()[currentRow][currentCol];
					grid->getGrid()[currentRow][currentCol] = nullptr;
					currentCol = destinationCol;

					this->daysSinceEating = 0;
					ateAnt = true;
				}
			}
		}

		moved = true;
	}
	else
	{
		// no adjacent ants - move normally and increment daysSinceEating
		Critter::move();
		daysSinceEating++;
	}
}

/*********************************************************************
** breed:
** 
*********************************************************************/
void Doodlebug::breed()
{
	if ((daysSinceBreeding >= 8 && grid->emptyAdjacent(currentRow, currentCol)))
	{
		bool spawned = false;

		while (!spawned)
		{
			Direction spawnDirection = static_cast<Direction>(getRandom(0, 3));

			if (spawnDirection == NORTH)
			{
				int spawnRow = currentRow - 1;
				if (spawnRow >= 0 && grid->checkEmpty(spawnRow, currentCol))
				{
					Doodlebug *doodlebug = new Doodlebug(grid, spawnRow, currentCol);
					grid->getGrid()[spawnRow][currentCol] = doodlebug;
					spawned = true;
				}
			}
			else if (spawnDirection == SOUTH)
			{
				int spawnRow = currentRow + 1;
				if (spawnRow < grid->getRows() && grid->checkEmpty(spawnRow, currentCol))
				{
					Doodlebug *doodlebug = new Doodlebug(grid, spawnRow, currentCol);
					grid->getGrid()[spawnRow][currentCol] = doodlebug;
					spawned = true;
				}
			}
			else if (spawnDirection == EAST)
			{
				int spawnCol = currentCol - 1;
				if (spawnCol >= 0 && grid->checkEmpty(currentRow, spawnCol))
				{
					Doodlebug *doodlebug = new Doodlebug(grid, currentRow, spawnCol);
					grid->getGrid()[currentRow][spawnCol] = doodlebug;
					spawned = true;
				}
			}
			else if (spawnDirection == WEST)
			{
				int spawnCol = currentCol + 1;
				if (spawnCol < grid->getCols() && grid->checkEmpty(currentRow, spawnCol))
				{
					Doodlebug *doodlebug = new Doodlebug(grid, currentRow, spawnCol);
					grid->getGrid()[currentRow][spawnCol] = doodlebug;
					spawned = true;
				}
			}
		}
		daysSinceBreeding = 0;
	}
	else
	{
		daysSinceBreeding++;
	}
}

/*********************************************************************
** getType: 
** 
*********************************************************************/
Type Doodlebug::getType()
{
	return DOODLEBUG;
}
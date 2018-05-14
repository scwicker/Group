/*********************************************************************
** Program name: Ant.cpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: Specification for the Ant class, which inherits from
** Critter. Includes Ant-specific method implementations, specifically
** the breed function. Implementation in Ant.cpp.
*********************************************************************/

#include "Ant.hpp"
#include "Grid.hpp"

#include "helpers.hpp"

/*********************************************************************
** Default constructor that calls Critter default constructor.
*********************************************************************/
Ant::Ant() : Critter()
{
}

/*********************************************************************
** Constructor for Ant which takes integer parameters representing
** the row position and column position of the ant on the grid. 
*********************************************************************/
Ant::Ant(Grid *grid, int currentRow, int currentCol) : Critter(grid, currentRow, currentCol)
{
}

/*********************************************************************
** breed: Ant implementation of the breed function. Spawns a new ant
** into an empty adjacent cell if it has not bred for 3 or more days.
** If no adjacent cell, ant is not spawned and daysSinceBreeding is
** incremented. Breeding will be attempted again next turn.
*********************************************************************/
void Ant::breed()
{
	if ((daysSinceBreeding >= 3 && grid->emptyAdjacent(currentRow, currentCol)))
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
					Ant *ant = new Ant(grid, spawnRow, currentCol);
					grid->getGrid()[spawnRow][currentCol] = ant;
					spawned = true;
				}
			}
			else if (spawnDirection == SOUTH)
			{
				int spawnRow = currentRow + 1;
				if (spawnRow < grid->getRows() && grid->checkEmpty(spawnRow, currentCol))
				{
					Ant *ant = new Ant(grid, spawnRow, currentCol);
					grid->getGrid()[spawnRow][currentCol] = ant;
					spawned = true;
				}
			}
			else if (spawnDirection == EAST)
			{
				int spawnCol = currentCol - 1;
				if (spawnCol >= 0 && grid->checkEmpty(currentRow, spawnCol))
				{
					Ant *ant = new Ant(grid, currentRow, spawnCol);
					grid->getGrid()[currentRow][spawnCol] = ant;
					spawned = true;
				}
			}
			else if (spawnDirection == WEST)
			{
				int spawnCol = currentCol + 1;
				if (spawnCol < grid->getCols() && grid->checkEmpty(currentRow, spawnCol))
				{
					Ant *ant = new Ant(grid, currentRow, spawnCol);
					grid->getGrid()[currentRow][spawnCol] = ant;
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
** getType: Returns the type of this object as a Type enum. Each critter
** inherited class should have its own version of this method.
*********************************************************************/
Type Ant::getType()
{
    return ANT;
}
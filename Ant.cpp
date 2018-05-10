/*********************************************************************
** Program name: Ant.cpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: 
** 
** 
*********************************************************************/

#include "Ant.hpp"
#include "Grid.hpp"
#include "helpers.hpp"

/*********************************************************************
** Default constructor
*********************************************************************/
Ant::Ant() : Critter()
{

}

/*********************************************************************
** 
** 
*********************************************************************/
Ant::Ant(Grid *grid, int currentRow, int currentCol) : Critter(grid, currentRow, currentCol)
{

}

/*********************************************************************
** breed:
** 
*********************************************************************/
void Ant::breed(std::vector<Ant*> ants)
{
	if ((stepsSurvived >= 3 && grid->emptyAdjacent(currentRow,currentCol))) {

        {
            bool antSpawned = false;
            while (!antSpawned)
            {
               Direction newAntCell = static_cast<Direction>(getRandom(0,3));
                switch (newAntCell)
                {
                    case NORTH:
                    {
                        if (currentRow -1 >= 0 && grid->checkEmpty(currentRow-1,currentCol)){
                            Ant* ant = new Ant(grid, currentRow-1, currentCol);
                            ants.push_back(ant);
                            grid->getGrid()[currentRow-1][currentCol] = ant;
                            antSpawned = true;
                        }

                        break;
                    }
                    case SOUTH:
                    {
                        if (currentRow +1 < grid->getRows() && grid->checkEmpty(currentRow+1,currentCol)){
                            Ant* ant = new Ant(grid, currentRow+1, currentCol);
                            ants.push_back(ant);
                            grid->getGrid()[currentRow+1][currentCol] = ant;
                            antSpawned = true;
                        }
                    }
                    case EAST:
                    {
                        if (currentCol -1 >= 0 && grid->checkEmpty(currentRow,currentCol-1)){
                            Ant* ant = new Ant(grid, currentRow, currentCol-1);
                            ants.push_back(ant);
                            grid->getGrid()[currentRow][currentCol-1] = ant;
                            antSpawned = true;
                        }
                    }
                    case WEST:
                    {
                        if (currentCol + 1 < grid->getCols() && grid->checkEmpty(currentRow,currentCol+1)){
                            Ant* ant = new Ant(grid, currentRow, currentCol+1);
                            ants.push_back(ant);
                            grid->getGrid()[currentRow][currentCol+1] = ant;
                            antSpawned = true;
                        }
                    }
                }
            }

        }
    }



}

Type Ant::getType()
{
    return ANT;
}
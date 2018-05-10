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
    stepsSurvived = 0;
    daysSinceEating = 0;
}

/*********************************************************************
** move: 
** 
*********************************************************************/
void Doodlebug::move()
{
    // // check if any destination cells have ants
    // if (grid->checkAnt(currentRow, currentCol + 1) || grid->checkAnt(currentRow, currentCol - 1) ||
    //     grid->checkAnt(currentRow + 1, currentRow) || grid->checkAnt(currentRow - 1, currentCol))
    // {
    //     bool ateAnt = false;
    //     while (!ateAnt)
    //     {
    //         Direction moveDirection = static_cast<Direction>(getRandom(0, 3));
            
    //         if (moveDirection == NORTH)
    //         {
    //             int destinationRow = currentRow - 1;
    //             // move only if space is ANT and within grid bounds
    //             if (destinationRow >= 0 && grid->checkAnt(destinationRow, currentCol))
    //             {
    //                 Critter ***gridArray = grid->getGrid();
    //                 gridArray[destinationRow][currentCol] = gridArray[currentRow][currentCol];
    //                 gridArray[currentRow][currentCol] = nullptr;
    //                 this->daysSinceEating = 0;
    //                 currentRow = destinationRow;
    //                 ateAnt = true;
    //             }
    //         }
    //         else if (moveDirection == SOUTH)
    //         {
    //             int destinationRow = currentRow + 1;
    //             if ((destinationRow < grid->getRows()) && grid->checkAnt(destinationRow, currentCol))
    //             {
    //                 Critter ***gridArray = grid->getGrid();
    //                 gridArray[destinationRow][currentCol] = gridArray[currentRow][currentCol];
    //                 gridArray[currentRow][currentCol] = nullptr;
    //                 this->daysSinceEating = 0;
    //                 currentRow = destinationRow;
    //                 ateAnt = true;
    //             }
    //         }
    //         else if (moveDirection == EAST)
    //         {
    //             int destinationCol = currentCol + 1;
    //             if ((destinationCol < grid->getCols()) && grid->checkAnt(currentRow, destinationCol))
    //             {
    //                 Critter ***gridArray = grid->getGrid();
    //                 gridArray[currentRow][destinationCol] = gridArray[currentRow][currentCol];
    //                 gridArray[currentRow][currentCol] = nullptr;
    //                 this->daysSinceEating = 0;
    //                 currentCol = destinationCol;
    //                 ateAnt = true;
    //             }
    //         }
    //         else if (moveDirection == WEST)
    //         {
    //             int destinationCol = currentCol - 1;
                
    //             if (destinationCol >= 0 && grid->checkAnt(currentRow, destinationCol))
    //             {
    //                 Critter ***gridArray = grid->getGrid();
    //                 gridArray[currentRow][destinationCol] = gridArray[currentRow][currentCol];
    //                 gridArray[currentRow][currentCol] = nullptr;
    //                 this->daysSinceEating = 0;
    //                 currentCol = destinationCol;
    //                 ateAnt = true;
    //             }
    //         }
    //     }
    // }
    // else
    // {
    //     Critter::move();
    // }
    
}


/*********************************************************************
** breed:
** 
*********************************************************************/
void Doodlebug::breed(std::vector<Doodlebug *> doodlebugs)
{
    if ((stepsSurvived >= 8 && grid->emptyAdjacent(currentRow, currentCol)))
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
                    doodlebugs.push_back(doodlebug);
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
                    doodlebugs.push_back(doodlebug);
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
                    doodlebugs.push_back(doodlebug);
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
                    doodlebugs.push_back(doodlebug);
                    grid->getGrid()[currentRow][spawnCol] = doodlebug;
                    spawned = true;
                }
            }
        }
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
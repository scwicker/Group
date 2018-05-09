//
// Created by Scott Wickersham on 5/5/18.
//

#include "Ant.hpp"
#include "Grid.hpp"
#include "helpers.hpp"

Ant::Ant() : Critter()
{
}

Ant::Ant(Grid *grid, int currentRow, int currentCol) : Critter(grid, currentRow, currentCol)
{
}






/*********************************************************************************************/
//Ant::breed(Grid& grid)
//if stepsSurvived % 3 == 0
//if an adjacent cell is empty
//        antSpawned = false
//until antSpawned
//pick a random number (0 - 3)
//pick adjacent cell above, below, left, or right based on random number
//if cell is empty
//        spawn new ant in cell
//        antSpawned = true
/**************************************************************************************************/
void Ant::breed(Grid &grid)
{
    //still need to check for edge cases in emptyAdjacent
	if ((stepsSurvived > 3 && grid.emptyAdjacent(currentRow,currentCol))) {

        {
            bool antSpawned = false;
            while (!antSpawned)
            {
               int newAntCell = getRandom(0,3);
                switch (newAntCell)
                {
                    case 1:
                    {
                        if (grid.checkEmpty(currentRow-1,currentCol)){
                            Ant* ant = new Ant(&grid, currentRow-1, currentCol);
                            antSpawned = true;
                        }

                        break;
                    }
                    case 2:
                    {
                        if (grid.checkEmpty(currentRow+1,currentCol)){
                            Ant* ant = new Ant(&grid, currentRow+1, currentCol);
                            antSpawned = true;
                        }
                    }
                    case 3:
                    {
                        if (grid.checkEmpty(currentRow,currentCol-1)){
                            Ant* ant = new Ant(&grid, currentRow, currentCol-1);
                            antSpawned = true;
                        }
                    }
                    case 4:
                    {
                        if (grid.checkEmpty(currentRow,currentCol+1)){
                            Ant* ant = new Ant(&grid, currentRow, currentCol+1);
                            antSpawned = true;
                        }
                    }
                }
            }

        }
    }



}


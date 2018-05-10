//
// Created by Scott Wickersham on 5/5/18.
//

#include "Doodlebug.hpp"
#include "Grid.hpp"
#include "helpers.hpp"


Doodlebug::Doodlebug() : Critter() {

}

Doodlebug::Doodlebug(Grid *grid, int currentRow, int currentCol) : Critter(grid, currentRow, currentCol) {
    stepsSurvived = 0;


}
/*******************************************************************************************/
void Doodlebug::breed(std::vector<Doodlebug*> doodlebugs) {
    {
        if ((stepsSurvived >= 8 && grid->emptyAdjacent(currentRow,currentCol))) {

            {
                bool doodlebugSpawned = false;
                while (!doodlebugSpawned)
                {
                    Direction newDoodlebugCell = static_cast<Direction>(getRandom(0,3));
                    switch (newDoodlebugCell)
                    {
                        case NORTH:
                        {
                            if (currentRow -1 >= 0 && grid->checkEmpty(currentRow-1,currentCol)){
                                Doodlebug* doodlebug = new Doodlebug(grid, currentRow-1, currentCol);
                                doodlebugs.push_back(doodlebug);
                                grid->getGrid()[currentRow-1][currentCol] = doodlebug;
                                doodlebugSpawned = true;
                            }

                            break;
                        }
                        case SOUTH:
                        {
                            if (currentRow +1 < grid->getRows() && grid->checkEmpty(currentRow+1,currentCol)){
                                Doodlebug* doodlebug = new Doodlebug(grid, currentRow+1, currentCol);
                                doodlebugs.push_back(doodlebug);
                                grid->getGrid()[currentRow+1][currentCol] = doodlebug;
                                doodlebugSpawned = true;
                            }
                        }
                        case EAST:
                        {
                            if (currentCol -1 >= 0 && grid->checkEmpty(currentRow,currentCol-1)){
                                Doodlebug* doodlebug = new Doodlebug(grid, currentRow, currentCol-1);
                                doodlebugs.push_back(doodlebug);
                                grid->getGrid()[currentRow][currentCol-1] = doodlebug;
                                doodlebugSpawned = true;
                            }
                        }
                        case WEST:
                        {
                            if (currentCol + 1 < grid->getCols() && grid->checkEmpty(currentRow,currentCol+1)){
                                Doodlebug* doodlebug = new Doodlebug(grid, currentRow, currentCol+1);
                                doodlebugs.push_back(doodlebug);
                                grid->getGrid()[currentRow][currentCol+1] = doodlebug;
                                doodlebugSpawned = true;
                            }
                        }
                    }
                }

            }
        }



    }

}


// THIS IS A MESS AND I'M ONLY USING AS TEST DRIVER FOR OTHER CLASSES RIGHT NOW
// PORTIONS OF BELOW CODE MAY BE ABLE TO BE USED (Random placement, creating critters...)
// BUT DON'T CONSIDER ANY OF THIS PART OF THE ACTUAL PROJECT - Paul

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Grid.hpp"
#include "Critter.hpp"
#include "helpers.hpp"

int main() {
    // seed rand in main to avoid reseeding
    srand(time(0));
    
    // create grid
    Grid* grid = new Grid(20, 20);

    // create and place ants!
    for (int i = 0; i < 100; i++)
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

        Ant* ant = new Ant(grid, randRow, randCol);
        grid->getGrid()[randRow][randCol] = ant;
    }

    // create and place doodlebugs!
    for (int i = 0; i < 5; i++)
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

        Doodlebug* doodlebug = new Doodlebug(grid, randRow, randCol);
        grid->getGrid()[randRow][randCol] = doodlebug;
    }

    std::cout << "Cols " << grid->getCols() << std::endl;
    std::cout << "Rows " << grid->getRows() << std::endl;
    
    // test 100 moves
    for (int i = 0; i < 1000; i++)
    {
        grid->print();
        std::cout << std::endl;

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

        // move all doodlebugs
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

        // breed all critters, starve doodlebugs, and age all critters
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
                        if (dynamic_cast<Doodlebug*>(grid->getGrid()[row][col])->getDaysSinceEating() >= 3)
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

        // check starving doodlebugs

        // age all critters
        for (int row = 0; row < grid->getRows(); row++)
        {
            for (int col = 0; col < grid->getCols(); col++)
            {
                if (grid->getGrid()[row][col] != nullptr)
                {
                    grid->getGrid()[row][col]->age();
                }
            }
        }

        std::cout << i << " iteration" << std::endl;
        //pause();
    }


    grid->print();
        std::cout << std::endl;
    return 0;
}
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

    // create vector to hold ant pointers
    std::vector<Ant*> ants;

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
        ants.push_back(ant);
        grid->getGrid()[randRow][randCol] = ant;
    }

    std::cout << "Cols " << grid->getCols() << std::endl;
    std::cout << "Rows " << grid->getRows() << std::endl;
    
    // test 100 moves
    for (int i = 0; i < 100; i++)
    {
        grid->print();
        std::cout << std::endl;
        for (unsigned i = 0; i < ants.size(); i++)
        {
            if (ants.at(i) != nullptr)
            {
                ants.at(i)->move();
            }  
        }
        //pause();
    }
grid->print();
        std::cout << std::endl;
    return 0;
}
//
// Created by Scott Wickersham on 5/5/18.
//

#include "Grid.hpp"

Grid::Grid(){
grid = new Critter **[20]; // CAN SET THE 20'S TO OUR ROWS AND COLUMNS LATER
                        // WE SHOULD PROBABLY AVOID RANDOM/VARIABLE ROWS/COLUMNS UNTIL AFTER DEBUGGING BASIC MOVEMENTS
    for (int i = 0; i<20; i++)
    {
        grid[i] = new Critter *[20];
        for (int k = 0; k < 20; k++)
        {
            grid [i][k] = nullptr;
        }
    }
}

Grid::Print(){
    for (int i = 0; i<20; i++)
    {

    }
}



Grid::~Grid() {
    for (int i = 0; i<20; i++)
    {
        for (int k = 0; k < 20; k++)
        {
            if (grid [i][k] != nullptr) {
                delete grid[i][k];
            }
        }
        delete grid[i];
    } //WILL NEED TO DEALLOCATE MORE HERE WHEN WE GET FUTHER
}

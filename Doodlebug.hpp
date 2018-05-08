//
// Created by Scott Wickersham on 5/5/18.
//

#ifndef GROUPPROJECT_DOODLEBUG_HPP
#define GROUPPROJECT_DOODLEBUG_HPP


#include "Critter.hpp"

class Doodlebug : public Critter
{
public:
    Doodlebug();
    Doodlebug(Grid *grid, int currentRow, int currentCol);
    virtual void breed();

};


#endif //GROUPPROJECT_DOODLEBUG_HPP

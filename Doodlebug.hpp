/*********************************************************************
** Program name: Doodlebug.hpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: 
** 
** 
*********************************************************************/

#ifndef GROUPPROJECT_DOODLEBUG_HPP
#define GROUPPROJECT_DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
    int daysSinceEating;
public:
    Doodlebug();
    Doodlebug(Grid *grid, int currentRow, int currentCol);
    virtual void move();
    virtual void breed();
    virtual Type getType();
    int getDaysSinceEating();
};


#endif //GROUPPROJECT_DOODLEBUG_HPP

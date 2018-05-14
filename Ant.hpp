/*********************************************************************
** Program name: Ant.hpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 10, 2018
** Description: Specification for the Ant class, which inherits from
** Critter. Includes Ant-specific method implementations, specifically
** the breed function. Implementation in Ant.cpp.
*********************************************************************/
#ifndef GROUPPROJECT_ANT_HPP
#define GROUPPROJECT_ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
public:
	Ant();
	Ant(Grid *grid, int currentRow, int currentCol);
	virtual void breed();
	virtual Type getType();
};

#endif //GROUPPROJECT_ANT_HPP

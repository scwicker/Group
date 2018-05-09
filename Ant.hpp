//
// Created by Scott Wickersham on 5/5/18.
//

#ifndef GROUPPROJECT_ANT_HPP
#define GROUPPROJECT_ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
public:
	Ant();
	Ant(Grid *grid, int currentRow, int currentCol);
	virtual void breed(Grid&);

};

#endif //GROUPPROJECT_ANT_HPP

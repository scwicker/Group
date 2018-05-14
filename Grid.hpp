/*********************************************************************
** Program name: Grid.hpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 8, 2018
** Description: Specification for the Grid class, which represents a
** grid, or board, filled with Critters (Ants and Doodlebugs).
** Grid size defaults to 20x20 or can be initialized with user provided 
** values. Implementation in Grid.cpp.
*********************************************************************/

#ifndef GROUPPROJECT_GRID_HPP
#define GROUPPROJECT_GRID_HPP

// critter class specifications
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

class Grid
{
private:
	Critter ***grid;
	int rows;
	int cols;
public:
	Grid();
	Grid(int rows, int cols);
	~Grid();
	void createGrid();
	Critter ***getGrid() const;
	int getRows() const;
	void setRows(int rows);
	int getCols() const;
	void setCols(int cols);
	bool checkEmpty(int row, int col); //checks each direction for empty
	void print() const;
	bool emptyAdjacent(int row, int col);
	bool checkAnt(int, int);
};

#endif //GROUPPROJECT_GRID_HPP

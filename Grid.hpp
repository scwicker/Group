//
// Created by Scott Wickersham on 5/5/18.
//

#ifndef GROUPPROJECT_GRID_HPP
#define GROUPPROJECT_GRID_HPP

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
	int getRows();
	void setRows(int rows);
	int getCols();
	int setCols(int cols);
	void print();
};

#endif //GROUPPROJECT_GRID_HPP

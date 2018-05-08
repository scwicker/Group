/*********************************************************************
** Program name: Critter.hpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 8, 2018
** Description: 
** 
** 
*********************************************************************/

#ifndef GROUPPROJECT_CRITTER_HPP
#define GROUPPROJECT_CRITTER_HPP

// forward declaration of Grid class
class Grid;

enum Direction {NORTH, SOUTH, EAST, WEST};

class Critter
{
  protected:
	int currentRow;
	int currentCol;
	int stepsSurvived;
	Grid *grid;

  public:
	Critter();
	Critter(Grid *grid, int currentRow, int currentCol);
	virtual ~Critter();
	int getRowPosition() const;
	bool setRowPosition(int currentRow);
	int getColPosition() const;
	bool setColPosition(int currentCol);
	int getStepsSurvived() const;
	Grid *getGrid();
	void setGrid(Grid *grid);
	virtual void move();
	virtual void breed();
	void age();
};

#endif //GROUPPROJECT_CRITTER_HPP

/*********************************************************************
** Program name: Grid.cpp
** Author: Group 1 - CS162 Spring 2018
** Date: May 8, 2018
** Description: Implementation of the Grid class, which represents a
** grid, or board, filled with Critters (Ants and Doodlebugs).
** Grid size defaults to 20x20 or can be initialized with user provided values.
*********************************************************************/

#include "Grid.hpp" // Grid class specification
#include <iostream>
#include <string>

const int ROWS_DEFAULT = 20;
const int COLS_DEFAULT = 20;

/*********************************************************************
** Default constructor. Initializes rows and columns to default values, 
** but sets grid to nullptr.
*********************************************************************/
Grid::Grid()
{
	this->rows = ROWS_DEFAULT;
	this->cols = COLS_DEFAULT;

	grid = nullptr;
}

/*********************************************************************
** Constructor that has takes parameters for rows and columns and creates
** the grid with that size.
*********************************************************************/
Grid::Grid(int rows, int cols)
{	
	grid = nullptr; // for nullptr check in createGrid();

	this->rows = rows;
	this->cols = cols;

	createGrid();
}

/*********************************************************************
** Destructor for Grid. Deallocates any memory that was dynamically
** allocated for Grid and the Critters within.
*********************************************************************/
Grid::~Grid()
{
	if (grid != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j] != nullptr)
				{
					delete grid[i][j];
				}
			}
			delete [] grid[i];
		}
		delete [] grid;
	}
}

/*********************************************************************
** createGrid: Creates a grid based on the current row and column values.
** Does not create re-create grid if already created.
*********************************************************************/
void Grid::createGrid()
{
	// only create grid if not already created
	if (grid == nullptr)
	{
		grid = new Critter **[rows];

		for (int i = 0; i < rows; i++)
		{
			grid[i] = new Critter *[cols];
			for (int j = 0; j < cols; j++)
			{
				grid[i][j] = nullptr;
			}
		}
	}
}

Critter*** Grid::getGrid() const
{
	return grid;
}

int Grid::getRows() const
{
	return rows;
}

void Grid::setRows(int rows)
{
	// only allow setting rows value if grid not yet created
	if (grid == nullptr && rows > 0)
	{
		this->rows = rows;
	}
}

int Grid::getCols() const
{
	return cols;
}

void Grid::setCols(int cols)
{
	// only allow setting cols value if grid not yet created
	if (grid == nullptr && cols > 0)
	{
		this->cols = cols;
	}
}

/*********************************************************************
** checkEmpty: Checks if a given space on the grid is empty. Takes two
** parameters for the row and column of the cell to check. Returns true
** if empty, false otherwise.
*********************************************************************/
bool Grid::checkEmpty(int row, int col)
{

	if (grid[row][col] == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** emptyAdjacent: Checks if adjacent space on the grid is empty. Takes two
** parameters for the row and column of the cell to check. Returns true
** if at least one adjacent cell is empty, false otherwise.
*********************************************************************/
bool Grid::emptyAdjacent(int row, int col)
{
	if ((row - 1) >= 0 && (grid[row - 1][col] == nullptr))
	{
		return true;
	}
	if ((row+1)<getRows()&&(grid[row+1][col] == nullptr))
	{
		return true;
	}
	if ((col - 1) >= 0 && grid[row][col - 1] == nullptr)
	{
		return true;
	}
	if ((col+1)<getCols()&& (grid[row][col+1] == nullptr))
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*********************************************************************
** print: Prints the current state of the grid to the terminal as chars
** using std::cout. Represents ants with 'O', doodlebugs with 'X', and
** null spaces with ' '.
*********************************************************************/
void Grid::print() const
{
	// only print grid if it exists
	if (grid != nullptr)
	{
		std::string line(cols + 2, '-');
		std::cout << line << std::endl; // border top

		for (int i = 0; i < rows; i++)
		{
			std::cout << '|';
			for (int j = 0; j < cols; j++)
			{
				if (dynamic_cast<Ant*>(grid[i][j]))
				{
					std::cout << 'O';
				}
				else if (dynamic_cast<Doodlebug*>(grid[i][j]))
				{
					std::cout << 'X';
				}
				else
				{
					std::cout << ' ';
				}
			}
			std::cout << '|';
			std::cout << std::endl;
		}

		std::cout << line << std::endl; // border bottom
	}
}

bool Grid::checkAnt(int row, int col) {
	 if (grid[row][col] != nullptr && grid[row][col]->getType() == ANT)
	 {
		 return true;
	 }
	 else
	 {
		 return false;
	 }
}


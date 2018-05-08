//
// Created by Scott Wickersham on 5/5/18.
//

#include "Grid.hpp"

const int ROWS_DEFAULT = 20;
const int COLS_DEFAULT = 20;

Grid::Grid()
{
	grid = nullptr;
	rows = ROWS_DEFAULT;
	cols = COLS_DEFAULT;
}

Grid::Grid(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;

	createGrid();
}

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

void Grid::createGrid()
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

int Grid::getRows()
{
	return rows;
}

void Grid::setRows(int rows)
{
	this->rows = rows;
}

int Grid::getCols()
{
	return cols;
}

int Grid::setCols(int cols)
{
	this->cols = cols;
}

void Grid::print()
{
	//todo: print grid
}

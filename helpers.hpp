/*********************************************************************
** Program name: helpers.hpp
** Author: John Casey
** Date: April 7, 2018
** Description: Helper and validation functions useful for various programs.
** See helpers.cpp for detailed function descriptions.
*********************************************************************/

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <climits> // INT_MIN, INT_MAX
#include <cfloat> // DBL_MAX
#include <cstdlib> // RAND_MAX
#include <string>

int getInt(int lower = INT_MIN, int upper = INT_MAX);

double getDouble(double lower = -DBL_MAX, double upper = DBL_MAX);

std::string getString();

char getYesNo();

int getRandom(int min = 0, int max = RAND_MAX);

void pause();

#endif
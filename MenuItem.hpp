/*********************************************************************
** Program name: MenuItem.hpp
** Author: John Casey
** Date: April 7, 2018
** Description: Specification for MenuItem, a class that stores information
** about an individual menu item. Used by the Menu class.
** Implementation in MenuItem.cpp
*********************************************************************/

#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <string>

class MenuItem
{
private:
	int choiceNumber;
	std::string description;
public:
	MenuItem(int choiceNumber, std::string description);
	int getChoiceNumber();
	std::string getDescription();
};

#endif
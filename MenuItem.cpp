/*********************************************************************
** Program name: MenuItem.hpp
** Author: John Casey
** Date: April 7, 2018
** Description: Implementation of MenuItem, a class that stores information
** about an individual menu item. Used by the Menu class.
** Specification in MenuItem.hpp
*********************************************************************/

#include "MenuItem.hpp" // MenuItem class specification

/*********************************************************************
** Constructor which takes two parameters and sets the choice number
** and description of the menu item.
*********************************************************************/
MenuItem::MenuItem(int choiceNumber, std::string description)
{
	this->choiceNumber = choiceNumber;
	this->description = description;
}

int MenuItem::getChoiceNumber()
{
	return choiceNumber;
}

std::string MenuItem::getDescription()
{
	return description;
}

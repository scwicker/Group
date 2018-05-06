/*********************************************************************
** Program name: Menu.hpp
** Author: John Casey
** Date: April 7, 2018
** Description: Specification for a reusable Menu class. Create a menu,
** add items, get validated choices from users, and print the menu to
** std::cout. Stores Menu items as objects of the MenuItem class. 
** Implementation in Menu.cpp.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "MenuItem.hpp"

#include <vector>
#include <string>

class Menu
{
private:
	std::string title;
	std::vector<MenuItem*> menuItems;
public:
	Menu();
	Menu(std::string title);
	void setTitle(std::string title);
	void addItem(int choiceNumber, std::string description);
	int getChoice();
	void print();
	~Menu();
};

#endif

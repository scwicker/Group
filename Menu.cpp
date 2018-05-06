/*********************************************************************
** Program name: Menu.hpp
** Author: John Casey
** Date: April 7, 2018
** Description: Implementation of a reusable Menu class. Create a menu,
** add items, get validated choices from users, and print the menu to
** std::cout. Stores Menu items as objects of the MenuItem class. 
** Specification in Menu.hpp.
*********************************************************************/

#include "Menu.hpp" // Menu class specification

#include "helpers.hpp" // getInt()
#include <iostream>
#include <string>


/*********************************************************************
** Default constructor for the Menu class.
*********************************************************************/
Menu::Menu()
{
	title = "";
}


/*********************************************************************
** Constructor allowing title to be set during initialization.
*********************************************************************/
Menu::Menu(std::string title)
{
	this->title = title;
}

/*********************************************************************
** Destructor that frees up free any dynamically allocated MenuItems.
*********************************************************************/
Menu::~Menu()
{
	// free memory for any MenuItems allocated
	for (unsigned i = 0; i < menuItems.size(); i++)
	{
		delete menuItems.at(i);
	}
}

/*********************************************************************
** setTitle: Set the menu title with a string.
*********************************************************************/
void Menu::setTitle(std::string title)
{
	this->title = title;
}

/*********************************************************************
** addItem: Adds a Menu Item to the Menu. As parameters, takes an integer
** representing menu choice number, and a string as the choice description.
** Menu items are dynamically allocated MenuItem objects.
*********************************************************************/
void Menu::addItem(int choiceNumber, std::string description)
{
	MenuItem* item = new MenuItem(choiceNumber, description);

	menuItems.push_back(item);
}

/*********************************************************************
** getChoice: Get a validated menu item choice from the user.  Keeps
** prompting until a valid choice is entered. Returns -1 if menu does
** not have any choices, otherwise returns the user's chosen option.
*********************************************************************/
int Menu::getChoice()
{
	if (menuItems.size() > 0)
	{
		int choice;
		bool validChoice = false;

		do
		{
			std::cout << "> ";

			choice = getInt();

			for (unsigned i = 0; i < menuItems.size() && !validChoice; i++)
			{
				if (choice == menuItems.at(i)->getChoiceNumber())
				{
					validChoice = true;
				}
			}

			if (!validChoice)
			{
				std::cout << "'" << choice << "' is not a valid menu item. " <<
					"Please enter a number corresponding to a menu item." << std::endl;
			}
		}
		while (!validChoice);

		return choice;
	}
	else
	{
		std::cout << "Menu is empty. No choices available." << std::endl;
		return -1;
	}

}

/*********************************************************************
** print: Uses std::cout to display the menu to the user. If a title
** is set, it is displayed above the menu.
*********************************************************************/
void Menu::print()
{
	if (title != "")
	{
		std::cout << this->title << std::endl;
		std::string line(title.length(), '-');
		std::cout << line << std::endl;
	}
	for (unsigned i = 0; i < menuItems.size(); i++)
	{
		std::cout << menuItems.at(i)->getChoiceNumber() << ". " << menuItems.at(i)->getDescription() << std::endl;
	}
	std::cout << std::endl;
}



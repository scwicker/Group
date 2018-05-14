/*********************************************************************
** Program name: helpers.cpp
** Author: John Casey
** Date: April 7, 2018
** Description: Validation and helper functions useful for various programs.
** Include the function header, helpers.hpp, to use.
*********************************************************************/

#include "helpers.hpp" // function prototypes

#include <cctype> // isdigit(), tolower()
#include <cstring> // strlen()
#include <iostream>
#include <string>
#include <sstream> // std::stringstream
#include <cstdlib> // rand()

/*********************************************************************
** getInt: Gets an integer from the user and returns it. Keeps prompting
** until a valid integer is provided. Floats and non-numeric types are
** rejected.
** Can optionally take two parameters indicating the lower and upper bounds.
** These default to INT_MIN and INT_MAX if no value is passed in.
** getInt() will validate that the value is within those bounds (inclusive).
*********************************************************************/
int getInt(int lower, int upper)
{
	bool gotInt = false;
	int num; // for user-provided integer

	do
	{
		std::string buffer;
		std::getline(std::cin, buffer);

		std::stringstream ss;
		ss << buffer;

		// idea to use stringstream for input validation from #CS162 Slack channel.
		if ((ss >> num && !(ss >> buffer)))
		{
			if (num >= lower && num <= upper)
			{
				gotInt = true;
			}
			else
			{
				std::cout << "Number is too large or small. Please enter an integer between " << lower << " and " << upper << "." << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid integer" << std::endl;
		}
	}
	while(!gotInt);

	return num;
}

/*********************************************************************
** getDouble: Gets an double from the user and returns it. Keeps prompting
** until a valid floating point number is provided.
** Can optionally take two parameters indicating the lower and upper bounds.
** These default to -DBL_MAX and DBL_MAX if no value is passed in.
** getDouble() will validate that the value is within those bounds (inclusive).
*********************************************************************/
double getDouble(double lower, double upper)
{
	bool gotDouble = false;
	double num; // for user-provided double

	do
	{
		std::cout << "> ";
		std::string buffer;
		std::getline(std::cin, buffer);

		std::stringstream ss;
		ss << buffer;

		if ((ss >> num && !(ss >> buffer)))
		{
			if (num >= lower && num <= upper)
			{
				gotDouble = true;
			}
			else
			{
				std::cout << "Number is too large or small. Please enter a floating point number between " << lower << " and " << upper << "." << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid floating point number." << std::endl;
		}
	}
	while(!gotDouble);

	return num;
}

/*********************************************************************
** getYesNo: Gets an Yes or No answer from a user. Keeps prompting
** until it receives 'y' or 'n' (case-insensitive).  Returns the answer
** to the caller as a lowercase char ('y' or 'n').
*********************************************************************/
char getYesNo()
{
	std::string buffer;
	bool gotYesNo = false;
	char answer;

	do
	{
		std::cout << "> ";
		getline(std::cin, buffer);

		if (buffer.length() == 1 && (tolower(buffer[0]) == 'y' || tolower(buffer[0]) == 'n') )
		{
			gotYesNo = true;
			answer = tolower(buffer[0]);
		}
		else
		{
			std::cout << "Invalid input. Please answer 'y' or 'n'." << std::endl;
		}
	}
	while (!gotYesNo);

	return answer;
}

/*********************************************************************
** getRandom: Returns a pseudorandom integer.  Optionally takes two
** parameters as minimum and maximum, and returns a number in that range.
** If no parameters are passed, returns a number between 0 and RAND_MAX.
** Assumes srand() has already been seeded.
*********************************************************************/
int getRandom(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

/*********************************************************************
** getString: gets a non-empty string from the user and returns it
** to the calling function.
*********************************************************************/
std::string getString()
{
	std::string buffer, stringIn;
	bool gotString = false;

	do
	{
		std::cout << "> ";
		getline(std::cin, buffer);

		if (!buffer.empty())
		{
			stringIn = buffer;
			gotString = true;
		}
		else
		{
			std::cout << "Please enter a valid, non-empty string of characters." << std::endl;
		}
	}
	while (!gotString);

	return stringIn;
}

/*********************************************************************
** pause: Use this function as a platform independent way to temporarily
** pause execution by awaiting user input. Execution continues after ENTER
** is pressed.
*********************************************************************/
void pause()
{
	std::cout << "Press ENTER to continue... ";
	std::string buffer;
	getline(std::cin, buffer);
	std::cout << std::endl;
}
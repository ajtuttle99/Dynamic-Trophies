#include <iostream>
#include <string>
#include <vector>
#include "Trophy.h"
using namespace std;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy (between 1 and 10)";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy (GOLD, SILVER, or BRONZE)";
const string PROMPT_FOR_NEW_NAME = "Please enter the new name of the Trophy";

// Menu choice handlers
void addTrophy(vector<Trophy*>& trophies);
void copyTrophy(vector<Trophy*>& trophies);
void deleteTrophy(vector<Trophy*>& trophies);
void renameTrophy(vector<Trophy*>& trophies);
void relevelTrophy(vector<Trophy*>& trophies);
void recolorTrophy(vector<Trophy*>& trophies);
void printTrophies(vector<Trophy*>& trophies);

// Input handlers
int printMenu();
Trophy* promptForTrophy();
string promptForString(const string& message);
int promptForInt(const string& message, int minimum, int maximum);
Color promptForColor(const string& message);

// Useful helper methods
string stringToUpper(string value);
int searchForTrophy(vector<Trophy*>& trophies, string name);

// This application allows for the management of a trophy collection
int main()
{
	
	cout << "***********************************************" << endl
		<< "Welcome to the Trophy editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies by" << endl
		<< "using this simple menu!" << endl
		<< "***********************************************" << endl;

	// Create a vector of Trophy objects
	vector<Trophy*> m_Trophies;

	// Loop the menu, allowing the user to select an action each time
	int input = 0;
	do
	{
		input = printMenu();
		switch (input)
		{
		case 1:		// Add a new Trophy
			addTrophy(m_Trophies);
			break;
		case 2:		// Copy an existing Trophy
			copyTrophy(m_Trophies);
			break;
		case 3:		// Delete an existing Trophy
			deleteTrophy(m_Trophies);
			break;
		case 4:		// Rename a Trophy
			renameTrophy(m_Trophies);
			break;
		case 5:		// Change the level of a Trophy
			relevelTrophy(m_Trophies);
			break;
		case 6:		// Change the color of a Trophy
			recolorTrophy(m_Trophies);
			break;
		case 7:		// Print all Trophies
			printTrophies(m_Trophies);
			break;
		case 8:		// Exit
			cout << "You have chosen to exit the application, good-bye!" << endl;
			break;
			
		default:
			cout << "That is not a recognized menu selection, choose again." << endl;
			break;
		}
	} while (input != 8);

	for (int i = 0; i < m_Trophies.size(); i++)
	{
		delete m_Trophies[i];
	}

	return 0;
}

// Print the menu to the user and accept their menu choice
int printMenu()
{
	int value = 0;

	cout << "-----------------------------------------" << endl
		<< "Please select an option :" << endl
		<< "1 - Add a new Trophy" << endl
		<< "2 - Copy a Trophy" << endl
		<< "3 - Delete a Trophy" << endl
		<< "4 - Rename a Trophy" << endl
		<< "5 - Change the level of a Trophy" << endl
		<< "6 - Change the color of a Trophy" << endl
		<< "7 - Print All the Trophies" << endl
		<< "8 - Exit the program" << endl
		<< "-----------------------------------------" << endl;
	do
	{
		string input = "";
		getline(cin, input);

		try
		{
			value = stoi(input);
		}
		catch (exception& e)
		{
			value = 0;
		}

		if (value < 1 || value > 8)
		{
			cout << "That is not a recognized menu selection, choose again." << endl;
			cout << "-----------------------------------------" << endl
				<< "Please select an option :" << endl
				<< "1 - Add a new Trophy" << endl
				<< "2 - Copy a Trophy" << endl
				<< "3 - Delete a Trophy" << endl
				<< "4 - Rename a Trophy" << endl
				<< "5 - Change the level of a Trophy" << endl
				<< "6 - Change the color of a Trophy" << endl
				<< "7 - Print All the Trophies" << endl
				<< "8 - Exit the program" << endl
				<< "-----------------------------------------" << endl;
		}

	} while (value < 1 || value > 8);

	return value;
}

// Add a new Trophy to the collection
void addTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to add a trophy." << endl;

	trophies.push_back(promptForTrophy());
}

// Delete an existing Trophy from the collection
void deleteTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to delete an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);

	// Find the trophy and if it exists, remove it from the vector
	if (searchForTrophy(trophies, name) != -1)
	{
		int location = searchForTrophy(trophies, name);
		delete trophies[location];
		trophies.erase(trophies.begin() + location);
	}
}

// Copy an existing Trophy in the collection
void copyTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to copy an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);

	// Find the trophy and if it exists, copy it and add the copy to the vector
	if (searchForTrophy(trophies, name) != -1)
	{
		Trophy* trophy = new Trophy(*trophies[searchForTrophy(trophies, name)]);
		trophies.push_back(trophy);
	}
}

// Rename an existing Trophy (change the name)
void renameTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to rename an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);

	// Find the trophy and if it exists, change its name
	if (searchForTrophy(trophies, name) != -1)
	{
		string newName = promptForString(PROMPT_FOR_NEW_NAME);
		trophies[searchForTrophy(trophies, name)]->SetName(newName);
	}
}

// Relevel an existing Trophy (change the level)
void relevelTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);

	// Find the trophy and if it exists, change its level
	if (searchForTrophy(trophies, name) != -1)
	{
		int newLevel = promptForInt(PROMPT_FOR_LEVEL, 0, 10);
		trophies[searchForTrophy(trophies, name)]->SetLevel(newLevel);
	}
}

// Recolor an existing Trophy (change the color)
void recolorTrophy(vector<Trophy*>& trophies)
{
	cout << "You have chosen to change the color of an existing trophy." << endl;
	string name = promptForString(PROMPT_FOR_NAME);

	// Find the trophy and if it exists, change its color
	if (searchForTrophy(trophies, name) != -1)
	{
		Color newColor = promptForColor(PROMPT_FOR_COLOR);
		trophies[searchForTrophy(trophies, name)]->SetColor(newColor);
	}
}

// Print all of the Trophies in the collection
void printTrophies(vector<Trophy*>& trophies)
{
	cout << "You have chosen to print all of the trophies." << endl;

	for (int i = 0; i < trophies.size(); i++)
	{
		cout << trophies[i]->print() << endl;
	}
}


// Ask the user for a Trophy, validate their responses
// Return the Trophy
Trophy* promptForTrophy()
{
	string name = promptForString(PROMPT_FOR_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, 1, 10);
	Color color = promptForColor(PROMPT_FOR_COLOR);

	Trophy* trophy = new Trophy(name, level, color);

	return trophy;
}

// Ask the user for a string, validate their response
// Return the string
string promptForString(const string& message)
{
	string value;
	cout << message << endl;

	do
	{
		getline(cin, value);

		if (value == "")
		{
			cout << "That is not a valid name.  Try again.";
		}
	}
		while (value == "");
	return value;
}

// Ask the user for an int, validate their response by
// checking that it is between minimum and maximum values
// Return the int
int promptForInt(const string& message, int minimum, int maximum)
{
	int value = 0;
	
	cout << message << endl;
	
	do
	{
		string input = "";
		getline(cin, input);

		try 
		{
			value = stoi(input);
		}
		catch (exception& e)
		{
			value = 0;
		}

		if (value < 1 || value > 10)
			cout << "That value is outside the acceptable range.  Try again." << endl;

		
	} while (value < 1 || value > 10);
	return value;
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper(string value)
{
	for (int i = 0; i < value.length(); i++)
	{
		char m_Char = value[i];
		value[i] = toupper(m_Char);
	}

	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color promptForColor(const string& message)
{
	Color color;
	string value;
	cout << message << endl;

	do
	{
		cin >> value;
		cin.ignore();

		value = stringToUpper(value);

		if (value == "BRONZE")
			color = BRONZE;
		else if (value == "SILVER")
			color = SILVER;
		else if (value == "GOLD")
			color = GOLD;
		else
		{
			cout << "That is not an acceptable color.  Try again." << endl;
		}
	} while (value != "BRONZE" && value != "SILVER" && value != "GOLD");

	return color;
}

// Search for a trophy in the collection by name
int searchForTrophy(vector<Trophy*>& trophies, string name)
{
	for (int i = 0; i < trophies.size(); i++)
	{
		if (name == trophies[i]->GetName())
		{
			return i;
		}
	}
	cout << "ERROR: The Trophy was not found" << endl;
	return -1;
}
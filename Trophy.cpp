#include "Trophy.h"
#include <string>
using namespace std;

#pragma region Constructors

// Default constructor
Trophy::Trophy()
{
	*m_name = "My Awesome Trophy";
	*m_level = 10;
	*m_TrophyColor = GOLD;
}

// Overload constructor
Trophy::Trophy(string name, int level, Color TrophyColor)
{
	m_name= new string(name);
	m_level = new int(level);
	m_TrophyColor = new Color(TrophyColor);
}

// Copy constructor
Trophy::Trophy(const Trophy& trophy)
{
	m_name =	 new string (trophy.GetName());
	m_level = new int(trophy.GetLevel());
	m_TrophyColor = new Color(trophy.GetColor());
}

#pragma endregion

// Destructor
Trophy::~Trophy()
{
	delete m_name;
	delete m_level;
	delete m_TrophyColor;
}

#pragma region Getters

// Returns trophy name
string Trophy::GetName() const
{
	return *m_name;
}

// Returns trophy level
int Trophy::GetLevel() const
{
	return *m_level;
}

// Returns trophy color
Color Trophy::GetColor() const
{
	return *m_TrophyColor;
}

#pragma endregion

#pragma region Setters

// Sets trophy name
string Trophy::SetName(string newName)
{
	*m_name = newName;
	return *m_name;
}

// Sets trophy level
int Trophy::SetLevel(int newLevel)
{
	*m_level = newLevel;
	return *m_level;
}

// Sets trophy color
Color Trophy::SetColor(Color newColor)
{
	*m_TrophyColor = newColor;
	return *m_TrophyColor;
}

#pragma endregion

// Prints all information of the trophy
string Trophy::print()
{
	string color;
	if (GetColor() == BRONZE)
		color = "BRONZE";
	else if (GetColor() == SILVER)
		color = "SILVER";
	else
		color = "GOLD";

	return "[ " + GetName() + " : " + to_string(GetLevel()) + " : " + color + " ]";
}

// Assignment constructor
Trophy& Trophy::operator=(const Trophy& trophy)
{
	m_name = new string(trophy.GetName());
	m_level = new int(trophy.GetLevel());
	m_TrophyColor = new Color(trophy.GetColor());

	return *this;
}
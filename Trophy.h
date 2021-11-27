#include <iostream>
#include <string>
using namespace std;

#ifndef TROPHY_H
#define TROPHY_H

enum Color
{
	GOLD,
	SILVER,
	BRONZE
};

class Trophy
{
public:
	Trophy();
	Trophy(string name, int level, Color TrophyColor);
	Trophy(const Trophy& trophy);
	~Trophy();

	string GetName() const;
	int GetLevel() const;
	Color GetColor() const;

	string SetName(string newName);
	int SetLevel(int newLevel);
	Color SetColor(Color newColor);

	string print();

	Trophy& operator=(const Trophy& vector);

private:
	string* m_name;
	int* m_level;
	Color* m_TrophyColor;
};


#endif
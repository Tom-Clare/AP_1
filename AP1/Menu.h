#pragma once
#include "ItemList.h"

using namespace std;

class Menu : public ItemList
{
public:
	Menu(std::string);
	std::vector<std::string> parseLine(std::string);
	std::string toString();
	std::string getHeading(std::string);
};


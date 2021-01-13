#pragma once

#include <string>
#include "Item.h"

using namespace std;

class MainCourse : public Item
{
public:
	char item_code = 'm';

	MainCourse(std::string, int, double);
	std::vector<std::string> Extras(); // See parent for further explaination
};


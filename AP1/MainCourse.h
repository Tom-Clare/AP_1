#pragma once

#include <string>
#include "Item.h"

using namespace std;

class MainCourse : public Item
{
public:
	std::string item_code() { return "m"; }

	MainCourse(std::string, int, double);
	std::vector<std::string> Extras(); // See parent for further explaination
};


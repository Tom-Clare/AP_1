#pragma once

#include <string>
#include "Item.h"

using namespace std;

class MainCourse : public Item
{
public:
	MainCourse(std::string, int, double);
	std::string toString() { return name(); }
};


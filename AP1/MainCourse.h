#pragma once

#include <string>
#include "Item.h"

using namespace std;

class MainCourse: public Item
{
public:
	std::string toString() { return get_name(); }
};


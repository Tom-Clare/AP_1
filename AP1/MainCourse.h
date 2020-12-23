#pragma once

#include <string>
#include "Item.h"

class MainCourse: public Item
{
public:
	std::string toString() { return get_name(); }
};


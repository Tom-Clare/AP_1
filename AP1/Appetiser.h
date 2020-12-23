#pragma once

#include <string>
#include "Item.h"

class Appetiser: public Item
{
private:
	bool shareable;
	bool twoForOne;
public:
	bool get_shareable() { return shareable; }
	bool get_twoForOne() { return twoForOne; }
	std::string toString() { return get_name(); }
};


#pragma once

#include <string>
#include "Item.h"

using namespace std;

class Appetiser : public Item
{
private:
	bool shareable_;
	bool twoForOne_;
public:
	Appetiser(std::string, int, double, std::string, std::string);
	std::vector<std::string> Extras(); // See parent for further explaination
	bool shareable() { return shareable_; }
	bool twoForOne() { return twoForOne_; }
	std::string toString() { return name(); }
};


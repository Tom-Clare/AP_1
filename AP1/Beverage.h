#pragma once

#include <string>
#include "Item.h"

using namespace std;

class Beverage : public Item
{
private:
	float abv_;
	int volume_;
public:
	Beverage(std::string, int, double, int, float);
	std::vector<std::string> Extras(); // See parent for further explaination
	bool isAlcoholic() { return abv() > 0 ? true : false; }

	string toString() { return name(); }

	// Getters
	float abv() { return abv_; }
	int volume() { return volume_; }
};


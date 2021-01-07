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
	string toString() { return name(); }
	float abv() { return abv_; }
	int volume() { return volume_; }
	bool isAlcoholic();
	// is alcoholic??
};


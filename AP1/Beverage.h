#pragma once

#include <string>
#include "Item.h"


class Beverage : public Item
{
private:
	float abv_;
	int volume_;
public:
	std::string item_code() { return "b"; }

	Beverage(std::string, int, double, int, float);
	std::vector<std::string> Extras(); // See parent for further explaination
	bool isAlcoholic() { return abv() > 0 ? true : false; }

	// Getters
	float abv() { return abv_; }
	int volume() { return volume_; }
};


#pragma once

#include <string>
#include "Item.h"

class Beverage
{
private:
	float abv;
	int volume;
public:
	float get_abv() { return abv; }
	int get_volume() { return volume; }
	// is alcoholic??
};


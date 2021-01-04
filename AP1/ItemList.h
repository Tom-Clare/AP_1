#pragma once

#include "Item.h"
#include <vector>

using namespace std;

class ItemList
{
public:
	std::vector<Item*> items;
	void Add(Item*);
};


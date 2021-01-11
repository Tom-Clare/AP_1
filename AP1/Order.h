#pragma once

#include "ItemList.h"
#include "Item.h"
#include "Menu.h"

using namespace std;

class Order : public ItemList
{
public:
	int GetIndex(Menu, int);
};


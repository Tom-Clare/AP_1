#pragma once

#include "ItemList.h"
#include "Item.h"
#include "Menu.h"

class Order : public ItemList
{
public:
	int getIndex(Menu, int);
	double calculateTotal();
	void printRecipt();
	std::string toString();
	void checkout();
};


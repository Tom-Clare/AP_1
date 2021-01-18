#pragma once

#include "ItemList.h"
#include "Item.h"
#include "Menu.h"

class Order : public ItemList
{
private:
	double total_;
public:
	int getIndex(Menu, int);
	std::string calculateTotal();
	void printReceipt();
	std::string toString();
	void checkout(Menu*);
	void confirmOrder(Menu*);
};


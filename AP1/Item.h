#pragma once

#include <string>

class Item
{
private:
	std::string name;
	int calories;
	double price;
public:
	virtual std::string toString() = 0;
	std::string get_name() { return name; }
	int get_calories() { return calories; }
	double get_price() { return price; }
};


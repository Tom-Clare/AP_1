#pragma once

#include <string>

using namespace std;

class Item
{
private:
	std::string name_;
	int calories_;
	double price_;
public:
	Item(std::string, int, double);
	virtual std::string toString() = 0;
	std::string name() { return name_; }
	int calories() { return calories_; }
	double price() { return price_; }
};


#pragma once

#include <string>
#include <vector>

using namespace std;

class Item
{
private:
	std::string name_;
	int calories_;
	double price_;
public:
	char item_code = 0;

	Item(std::string, int, double);
	virtual std::string toString();
	virtual std::vector<std::string> Extras() = 0; // This should return a vector of all extra attributes of the dervied class
	std::string FormatExtra(std::vector<std::string>); // This is a helper method for Extras()
	std::string name() { return name_; }
	int calories() { return calories_; }
	double price() { return price_; }
};


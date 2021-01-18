#include "Helper.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

// Gives out a formatted string
std::string Helper::FormatDoubleToString(double display_value) {
	std::string s;
	std::stringstream sstream;
	sstream.setf(std::ios::fixed);
	sstream.precision(2); // This is how many digits after the decimal point there'll be
	sstream << display_value;

	return sstream.str();
}

void Helper::ParameterError() {
	std::cout << "Invalid parameters. Type \"help\" to see the help section.\n";
}

void Helper::CleanExit(Menu* menu) {
	//iterate through menu.items and remove them all!
	for (auto& item : menu->items) {
		delete item;
	}

	exit(0);
}
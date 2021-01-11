#include "Beverage.h"
#include "Helper.h"

Beverage::Beverage(std::string name, int calories, double price, int volume, float abv) : Item(name, calories, price) {
	abv_ = abv;
	volume_ = volume;
}

std::vector<std::string> Beverage::Extras() { // returns all derived class associated attributes
	std::vector<std::string> output;

	output.push_back(std::to_string(volume_) + "ml");
	if (isAlcoholic()) {
		output.push_back(Helper::FormatDoubleToString(abv_) + "%");
	}

	return output;
}
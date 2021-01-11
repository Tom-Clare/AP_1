#include "Appetiser.h"

Appetiser::Appetiser(std::string name, int calories, double price, std::string shareable, std::string twoForOne) : Item(name, calories, price) {
	if (shareable == "y") {
		shareable_ = 1;
	} 
	else if (shareable == "n") {
		shareable_ = 0;
	}

	if (twoForOne == "y") {
		twoForOne_ = 1;
	}
	else if (twoForOne == "n") {
		twoForOne_ = 0;
	}
	
	return;
}

std::vector<std::string> Appetiser::Extras() { // returns all derived class associated attributes
	std::vector<std::string> output;

	if (shareable_) { output.push_back("shareable"); }
	if (twoForOne_) { output.push_back("2-4-1"); }

	return output;
}

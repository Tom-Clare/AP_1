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

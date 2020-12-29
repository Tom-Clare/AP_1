#include "Appetiser.h"

Appetiser::Appetiser(std::string name, int calories, double price, bool shareable, bool twoForOne) : Item(name, calories, price) {
	shareable_ = shareable;
	twoForOne_ = twoForOne;
	return;
}

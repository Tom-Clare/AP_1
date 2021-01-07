#include "Beverage.h"

Beverage::Beverage(std::string name, int calories, double price, int volume, float abv) : Item(name, calories, price) {
	abv_ = abv;
	volume_ = volume;
}
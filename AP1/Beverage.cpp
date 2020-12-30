#include "Beverage.h"

Beverage::Beverage(std::string name, int calories, double price, float abv, int volume) : Item(name, calories, price) {
	abv_ = abv;
	volume_ = volume;
}
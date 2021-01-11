#include "MainCourse.h"

MainCourse::MainCourse(std::string name, int calories, double price) : Item(name, calories, price) {
	return;
}

std::vector<std::string> MainCourse::Extras() { // returns all derived class associated attributes
	std::vector<std::string> output;
	return output;
}
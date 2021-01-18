#pragma once

#include "Menu.h"
#include "Order.h"

#include <string>

class Helper
{
public:
	static std::string FormatDoubleToString(double);
	static void ParameterError();
	static void CleanExit(Menu*);
};


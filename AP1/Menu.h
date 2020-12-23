#pragma once
#include "ItemList.h"

class Menu : public ItemList
{
public:
	Menu(std::string conf_file);
	std::string toString();
};


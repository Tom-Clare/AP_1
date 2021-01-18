#include "ItemList.h"
#include <iostream>

void ItemList::add(Item* item_pointer, char type_code, bool output) {
	items.push_back(item_pointer);
	type_codes.push_back(type_code);

	if (output) {
		auto(*added_obj) = item_pointer;
		std::cout << added_obj->name() << " added to order!" << endl;
	}
}

void ItemList::remove(int index, bool output) {
	items.erase(items.begin() + index);

	if (output) {
		std::cout << "Removed from order!" << endl;
	}
}
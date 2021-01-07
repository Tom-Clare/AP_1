#include "ItemList.h"

void ItemList::Add(Item* item_pointer, char type_code) {
	items.push_back(item_pointer);
	type_codes.push_back(type_code);
}
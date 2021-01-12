#include "Order.h"
#include "Menu.h"
#include <iostream>

// Write the checkout confirmation screen, reusing Menu's toString() method.

int Order::getIndex(Menu menu, int menu_number) { // Get index of item in menu object's itemlist from the number shown on the menu

	Item* menu_item_pointer = menu.items[menu_number-1]; // Access menu's itemList, get pointer for given menu number

	for (std::size_t i = 0; i != this->items.size(); ++i) { // Iterate over order.items...
		if (menu_item_pointer == this->items.at(i)) { // until pointers match
			return i; // If found, return index
		}
	}

	return -1; // If not found, return -1 (as an error code!)
}

void Order::checkout() {
	std::cout << this->toString();
}

std::string Order::toString() {
	std::string output = "";

	// We need to print out the order items in the same way as we did with the menu
	output.append("========== Checkout ==========\n");

	for (std::size_t i = 0; i != this->items.size(); ++i) {

		auto(*current_item) = this->items[i]; // can be used to interact with object
		output.append(current_item->toString());
		output.append("\n");

	}

	return output;
}
#include "Item.h"

Item::Item(std::string name, int calories, double price) {
	name_ = name;
	calories_ = calories;
	price_ = price;
	return;
}

std::string Item::FormatExtra(std::vector<std::string> extras_list) {
	if (extras_list.empty()) {  // If nothing in the vector was passed...
		return ""; // Return empty string
	}

	std::string output; // Initilise output string

	output.append("(");
	for (std::size_t i = 0; i != extras_list.size(); ++i) {
		output.append(extras_list[i]); // Append element

		if (i + 1 != extras_list.size()) {
			output.append(", "); // Add connector if the next element is not the last one
		}
	}
	output.append(")");

	return output;
}
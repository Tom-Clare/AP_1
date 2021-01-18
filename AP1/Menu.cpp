#include "Menu.h"
#include "Item.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
#include "Helper.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

Menu::Menu(std::string given_conf_file) {
	std::ifstream active_conf_file (given_conf_file); // Select and open the given file
	std::string line;
	std::vector<std::string> menu_item;

	if (active_conf_file.is_open()) { // Successfully opened
		while (std::getline(active_conf_file, line)) {
			menu_item = Menu::parseLine(line); // Parse this line into a vector of tokens.
			try {
				Item* new_item_address;
				if (menu_item[0] == "a") {
					new_item_address = new Appetiser(menu_item[1], std::stoi(menu_item[3]), std::stod(menu_item[2]), menu_item[4], menu_item[5]);
					add(new_item_address, 'a', false);
				}
				else if (menu_item[0] == "m") {
					new_item_address = new MainCourse(menu_item[1], std::stoi(menu_item[3]), std::stod(menu_item[2]));
					add(new_item_address, 'm', false);
				}
				else if (menu_item[0] == "b") {
					new_item_address = new Beverage(menu_item[1], std::stoi(menu_item[3]), std::stod(menu_item[2]), std::stoi(menu_item[6]), std::stof(menu_item[7]));
					add(new_item_address, 'b', false);
				}
			}
			catch (const std::exception& e) {
				cout << "ERROR: menu.csv is invalid.";
				exit(EXIT_FAILURE);
			}
		}
		active_conf_file.close();
	}
	else {
		cout << "ERROR: menu.csv could not be opened.";
		exit(EXIT_FAILURE);
	}
}

std::vector<std::string> Menu::parseLine(std::string line) {
	std::string token;
	std::vector<std::string> result;
	std::stringstream line_stream;
	
	line_stream.str(line);

	while (std::getline(line_stream, token, ',')) {
		result.push_back(token);
	}
	return result;
}

// This will return the entire menu as a string
std::string Menu::toString() {

	std::string output = "";
	std::string old = "";
	std::string current = "";
	std::string heading = "";

	for (std::size_t i = 0; i < items.size(); i++) {

		auto(*current_item) = items[i]; // can be used to interact with object

		current = type_codes[i]; // Get current item catergory
		if (current != old) { // new subheading
			heading = getHeading(current);
			output.append("--------------- " + heading + " ---------------\n");
		}

		output.append("(" + std::to_string(i + 1) + ") "); // Display index number + 1
		output.append(current_item->toString()); // Output object

		output.append("\n");

		old = current; // Save this type code as previously used
	}

	return output; // Format menu here
}

// This will return the respective heading for the type of menu item
std::string Menu::getHeading(std::string type_code) { 
	if (type_code == "a") {
		return "Appetisers";
	}
	else if (type_code == "m") {
		return "Main Courses";
	}
	else if (type_code == "b") {
		return "Beverages";
	}

	return "";
}

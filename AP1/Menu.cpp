#include "Menu.h"
#include "Item.h"
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"
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
					Add(new_item_address, 'a');
				}
				else if (menu_item[0] == "m") {
					new_item_address = new MainCourse(menu_item[1], std::stoi(menu_item[3]), std::stod(menu_item[2]));
					Add(new_item_address, 'm');
				}
				else if (menu_item[0] == "b") {
					new_item_address = new Beverage(menu_item[1], std::stoi(menu_item[3]), std::stod(menu_item[2]), std::stoi(menu_item[6]), std::stof(menu_item[7]));
					Add(new_item_address, 'b');
				}
			}
			catch (const std::exception& e) {
				cout << "ERROR: menu.csv is invalid.";
				exit(EXIT_FAILURE);
			}
			/////////////////////////  TODO: Objects created, add them tot hte vector of pointers in Menu.
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

std::string Menu::toString() {
	std:string output = "";
	for (int i = 0; i < items.size(); i++) {
		if (type_codes[i] == 'a') { // Appetiser
			
		}
		else if (type_codes[i] == 'm') { // Main Course

		}
		else if (type_codes[i] == 'b') { // Beverage

		}
	}
	return output; // Format menu here
}
#include "Menu.h"
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
			cout << menu_item[0];
			if (menu_item[0] == "a") {
				// start try catch
				Appetiser * new_item_address = new Appetiser(menu_item[1], std::stoi(menu_item[3]), std::stod(menu_item[2]), menu_item[4], menu_item[5]);
				// if failed, not sure, error somehow?
			}
			/////////////////////////  TODO: Create objects with given letter code from the csv. Will have to cast the indexes as we pass them. Need to do Beverage and MainCourse now
		}
		active_conf_file.close();
	}
	else {
		cout << ":("; // File wasn't successfully opened. Maybe exit gracefully?
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
	return ""; // Format menu here
}
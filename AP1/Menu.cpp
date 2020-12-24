#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Menu::Menu(std::string given_conf_file) {
	std::ifstream active_conf_file (given_conf_file); // Select and open the given file
	std::string line;
	std::vector<std::string> menu_item;

	if (active_conf_file.is_open()) { // Successfully opened
		while (std::getline(active_conf_file, line)) {
			std::cout << line;  // Remove before production :P
			Menu::parseLine(line) = menu_item; // Parse the individual line into a vector of tokens which we can then send to be created as an object.
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
		result.push_back(token);  /////////////////////////////////////Currently here - we need to see if this is actually working, and then we need to find out what to do with it!! :D
	}
	return result;
}

std::string Menu::toString() {
	return ""; // Format menu here
}
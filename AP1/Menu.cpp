#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

Menu::Menu(std::string given_conf_file) {
	std::ifstream active_conf_file (given_conf_file); // Select and open the given file
	std::string line;
	if (active_conf_file.is_open()) { // Successfully opened
		while (std::getline(active_conf_file, line)) {
			std::cout << line;  ////////////////////////////////////////// NEXT TASK: SPLIT LINE ASN ASSEMBLE ITEM OBJECT. SAVE POINTER I SUPPOSE :P
		}
		active_conf_file.close();
	}
}

std::string Menu::toString() {
	return ""; // Format menu here
}
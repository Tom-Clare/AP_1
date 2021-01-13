/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "Helper.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			// check all items in the array, if all subsequent elements are ints, continue. If not, spit out invalid command!
			bool valid = true;
			vector<int> choices;
			
			try {
				for (std::size_t i = 1; i != parameters.size(); ++i) {
					choices.push_back(std::stoi(parameters[i]));
				}
			}
			catch (exception& e) {
				Helper::ParameterError();
				continue; // Continue outer loop, which will propt user for new command
			}

			// Now that we are sure that our parameters are valid, we can create the objects
			Item* choice;
			for (int index : choices) {
				index--; // Remove 1 from index, since displayed/given index will be one higher than what it is in the menu list
				choice = menu.items.at(index); // Fetch pointer
				char type_code = menu.type_codes.at(index); // Fetch type code
				order.add(choice, type_code); // Add to order list
			}
		}
		else if (command.compare("remove") == 0)
		{
			if (parameters.size() == 2) {
				int choice;
				try {
					choice = std::stoi(parameters[1]); // Checking for non-int error
				}
				catch (exception& e) {
					Helper::ParameterError();
					continue; // Make user retry command
				}

				int order_item_index = order.getIndex(menu, choice); // This will be the index of the item in orders "items" vector. A value of -1 means not found.
				if (order_item_index == -1) { // Checking if we even have a pointer to that Item object in order.items
					Helper::ParameterError();
					continue; // Make user retry command
				}

				// We do!
				order.remove(order_item_index);
			}
		}
		else if (command.compare("checkout") == 0)
		{
			order.checkout(menu);
		}
		else if (command.compare("help") == 0)
		{

		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}
#include <iostream>
#include <set>
#include <string>
#include <algorithm>


int main()
{
	std::set <std::string> MaxList;
	std::set <std::string> PatList;
	std::set <std::string> CombinedList;
	std::string temp;
	std::cout << "If there are some friends with identical names, please, add something to their name to differentiate them (e.x. \"Peter1\", \"Peter jr\" or \"Peter Smith\" \n";
	std::cout << "Enter Max's friends or \"quit\" to quit: ";
	while (std::getline(std::cin, temp) && temp != "quit") {
		MaxList.insert(temp);
	}

	std::cout << "Enter Pat's friends or \"quit\" to quit: ";
	while (std::getline(std::cin, temp) && temp != "quit") {
		PatList.insert(temp);
	}
	CombinedList.insert(MaxList.begin(), MaxList.end());
	CombinedList.insert(PatList.begin(), PatList.end());
	std::cout << "\nShowing Max's friends: ";
	for (auto i = MaxList.begin(); i != MaxList.end(); i++) {
		std::cout << *i << ' ';
	}

	std::cout << "\nShowing Pat's friends: ";
	for (auto i = PatList.begin(); i != PatList.end(); i++) {
		std::cout << *i << ' ';
	}

	std::cout << "\nShowing combined list of friends: ";
	for (auto i = CombinedList.begin(); i != CombinedList.end(); i++) {
		std::cout << *i << ' ';
	}
}


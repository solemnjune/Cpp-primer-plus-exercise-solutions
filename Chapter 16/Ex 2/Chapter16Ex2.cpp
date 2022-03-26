#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

bool checkPali(const std::string& inp);

int main()
{
	std::string input;
	std::cout << "Enter a word to check if it is a palindrome  or \"quit\" to quit: ";
	while (std::getline(std::cin, input) && input != "quit") {
		if (checkPali(input) == true) {
			std::cout << input << " is a palindrome !" << std::endl;
		}
		else {
			std::cout << input << " is not a palindrome !" << std::endl;

		}

		std::cout << std::endl;
		std::cout << "Enter a word to check if it is a palindrome  or \"quit\" to quit: ";
	}
}

bool checkPali(const std::string& inp) {
	std::string temp;
	for (size_t i = 0; i < inp.size(); i++) {
		if (isalpha(inp[i])) {
			temp.push_back(tolower(inp[i]));
		}
	}
	for (size_t i = 0, j = temp.size() - 1; i < j; i++, j--) {
		if (temp[i] != temp[j]) {
			return false;
		}
	}

	return true;
}

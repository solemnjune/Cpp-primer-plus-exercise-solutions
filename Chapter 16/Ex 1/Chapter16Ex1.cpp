#include "pch.h"
#include <iostream>
#include <string>

bool checkPali(const std::string& inp) {
	for (size_t i = 0, j = inp.size()-1; i < j; i++, j--) {
		if (inp[i] != inp[j]) {
			return false;
		}
	}
	return true;
}

int main()
{
	std::string input;
	std::cout << "Enter a word to check if it is a palindrome or \"quit\" to quit: ";
	while (std::getline(std::cin, input) && input != "quit") {
		if (checkPali(input) == true) {
			std::cout << input << " is a palindrome!" << std::endl;
		}
		else {
			std::cout << input << " is not a palindrome!" << std::endl;

		}

		std::cout << std::endl;
		std::cout << "Enter a word to check if it is a palindrome or \"quit\" to quit: ";
	}
}

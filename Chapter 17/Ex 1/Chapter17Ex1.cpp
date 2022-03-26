#include "pch.h"
#include <iostream>

int main()
{
	using namespace std;

	cout << "This programm count number of character of the imput. Count will stop with the first $ symbol " << endl;
	cout << "Enter text: ";
	char ch;
	int count = 0;
	while (cin.get(ch))
	{
		if (ch == '$') {
			cin.putback(ch);
			break;
		}
		count++;
	}
	cout << "This text has " << count << " characters" << endl;
	cout << "The next character in input is: " << (char)cin.peek();
}

//компилировать вместе с файлом People.cpp
#include "pch.h"
#include "People.h"
#include <ctime>
const int SIZE = 5;

int main()
{
	std::srand(std::time(0));

	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Person* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the person category:\n"
			<< "h: person  g: gunslinger "
			<< "p: poker player  b: bad dude  q: quit\n";
		cin >> choice;
		while (strchr("hgpbq", choice) == NULL)
		{
			cout << "Please enter:  h, g, p, b or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'h':   lolas[ct] = new Person;
			break;
		case 'g':   lolas[ct] = new Gunslinger;
			break;
		case 'p':   lolas[ct] = new PokerPlayer;
			break;
		case 'b':   lolas[ct] = new BadDude;
			break;
		default:
			cout << " ERROR " << endl;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++) {
		delete lolas[i];
	}
	cout << "Bye.\n";

	
	return 0;
}

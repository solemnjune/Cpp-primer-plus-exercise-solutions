// компилировать вместе с файлом Worker.cpp
#include "pch.h"
#include "Worker.h" 
#include "QueueTp.h"
#include <iostream>

const int SIZE = 5;
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;


	QueueTp <Worker*> queue(SIZE);

	Worker* item;

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':   item = new Waiter;
			cin.get();
			item->Set();
			break;
		case 's':   item = new Singer;
			cin.get();
			item->Set();
			break;
		case 't':   item = new SingingWaiter;
			cin.get();
			item->Set();
			break;
		default:
			break;
		}
		
		queue.enqueue(item);
	}

	cout << "\nHere is your staff:\n";
	while (queue.isempty() != true) {
		queue.dequeue(item);
		item->Show();
		delete item;
	}
	cout << "Bye.\n";

	
	return 0;
}
//-------------------------------------------------------------------------------------------------

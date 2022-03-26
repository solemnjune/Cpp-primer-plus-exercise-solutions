//компилировать вместе с файлом People.cpp
#include "pch.h"
#include "People.h"
using namespace std;

int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	cout << endl;
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	cout << endl;

	fink fi("Matt", "Oggs", "Oiler", "JunoBarr");
	cout << fi << endl;
	fi.ShowAll();
	cout << endl;

	highfink hf(ma, "Curly Kew"); // укомплектовано? 
	hf.ShowAll();
	cout << endl;

	cout << "Press enter for next phase:\n";
	// Нажать клавишу enter для следующей фазы 
	cin.get();
	//cin.get();
	highfink hf2;
	hf2.SetAll();
	cout << "Using an abstr_emp * pointer:\n";
	// Использование указателя abstr_emp * 
	abstr_emp * tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++) {
		tri[i]->ShowAll();
		cout << endl;
	}
	return 0;
}

#include "pch.h"
#include <iostream> 
#include "Classes.h" // будет содержать #include cd.h 

using namespace std;

void Bravo(const Cd & disk);

int main()
{
	Cd cl("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &cl;
	// Непосредственное использование объектов 
	cout << "Using object directly:\n";
	cl.Report(); // использование метода Cd 
	c2.Report(); // использование метода Classic 
	// Использование указателя на объекты типа cd * 
	cout << "Using type cd * pointer to objects: \n";
	pcd->Report(); // использование метода Cd для объекта cd 
	pcd = &c2;
	pcd->Report(); // использование метода Classic для объекта classic 
	// Вызов функции с аргументом-ссылкой на Cd 
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(cl);
	Bravo(c2);
	// Тестирование присваивания 
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	

	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}

// компилировать с файлом wine.cpp
#include "pch.h"
#include "Wine.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	cout << "Enter name of wine: "; // ввод названия вина 
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: "; // ввод количества годов сбора винограда 
	int yrs;
	cin >> yrs;
	Wine holding(lab, yrs); // сохранение названия, лет, 
	// создание массивов из yrs элементов 
	holding.GetBottles(); // предложение ввести год и количество бутылок 
	holding.Show(); // вывод содержимого объекта 
	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };
	// Создание нового объекта, инициализация 
	// с использованием данных из массивов у и b 
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() // используется метод Label() 
		<< ": " << more.sum() << endl; // используется метод sum() 
	cout << "Bye\n";
	return 0;
}

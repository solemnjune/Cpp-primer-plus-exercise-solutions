#include "pch.h"
#include <iostream>
#include <cstdlib> // прототипы rand(), srand() 
#include <ctime> // прототип time() 
#include "vect.h"

//-------------------------------------------------------------------------------------------------
int main()
{
	std::ofstream fout;
	fout.open("OutputTesting.txt");
	using namespace std;
	using VECTOR::Vector;
	srand(time(0)); // начальное значение для генератора случайных чисел 
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit) : ";
	// Ввод заданного расстояния (q для завершения) 
	while (cin >> target)
	{
		cout << "Enter step length: "; // ввод длины шага 
		if (!(cin >> dstep))
			break;
		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		while (result.magval() < target)
		{
			fout << steps << ":" << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			
		}
		fout << steps << ":" << result << endl;
		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl; // вывод позиции после steps шагов 
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl; // вывод среднего расстояния на один шаг 

		result.rect_mode();
		fout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		fout << result << endl; // вывод позиции после steps шагов 
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps << endl; // вывод среднего расстояния на один шаг 
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit) : ";
		// Ввод заданного расстояния (q для завершения) 
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}

#include "pch.h"
#include <cmath> // или math.h, пользователям UNIX может потребоваться флаг -lm 
#include "exc_mean.h" 

//-------------------------------------------------------------------------------------------------
// Прототипы функций 
double hmean(double a, double b);
double gmean(double a, double b);
//-------------------------------------------------------------------------------------------------
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two numbers: ";	// запрос на ввод двух чисел 
	while (cin >> x >> y)
	{
		try {                 // начало блока try 
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;	// вывод среднего гармонического 
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << endl;	// вывод среднего геометрического 
			cout << "Enter next set of numbers <q to quit>: ";	// ввод следующей пары чисел ' 
		}// конец блока try 
		catch (bad_hmean & bg)   // начало блока catch 
		{
			cout << bg.what();
			cout << "Try again.\n";	// необходимо повторить попытку 
			continue;
		}
		catch (bad_gmean & hg)
		{
			cout << hg.what();
			
			cout << "Sorry, you don't get to play any more.\n";	// завершение работы 
			break;
		} // конец блока catch 
	}
	cout << "Bye!\n";

	
	return 0;
}
//-------------------------------------------------------------------------------------------------
double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean();
	return 2.0 * a * b / (a + b);
}
//-------------------------------------------------------------------------------------------------
double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean();
	return std::sqrt(a * b);
}
//-------------------------------------------------------------------------------------------------

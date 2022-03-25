// компилировать вместе с файлом SourcePort.h
#include "pch.h"
#include "port.h"

int main()
{
	Port test;
	Port test2{ "Jew apples", "tawny", 20 };
	std::cout << "Checking empty Port: " << std::endl;
	test.Show();
	std::cout <<std::endl<< "Checking assignment operator with initialized object(Port): " << std::endl;
	test = test2;
	std::cout << test << std::endl;

	std::cout << std::endl <<  "Checking empty VintagePort: " << std::endl;
	VintagePort vintageTest;
	vintageTest.Show();

	VintagePort vinTest2{ "Shawnty", 25, "The Noble", 1970 };
	VintagePort vinTest3{ "Stihlls", 5, "Old Velvet", 1934 };
	VintagePort vinTest4(vinTest3);
	std::cout << std::endl << "Checking copy constructer with initialized object(VintagePort): " << std::endl;
	vinTest4.Show();

	std::cout << std::endl << "Checking assignment operator with initialized object(VintagePort): " << std::endl;
	vintageTest = vinTest2;
	std::cout << vintageTest << std::endl;

	std::cout << std::endl << "Checking operations with bottles (VintagePort): " << std::endl;
	std::cout << vinTest4 << std::endl;
	std::cout << "Vin bottles: " << vinTest4.BottleCount() << std::endl;
	vinTest4 -= 10;
	std::cout << "Vin bottles-10: " << vinTest4.BottleCount() << std::endl;
	vinTest4 += 20;
	std::cout << "Vin bottles+20: " << vinTest4.BottleCount() << std::endl;
	vinTest4 -= 9;
	std::cout << "Vin bottles-9: " << vinTest4.BottleCount() << std::endl;

	std::cout << vinTest4 << std::endl;

}

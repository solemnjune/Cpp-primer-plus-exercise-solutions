#include "pch.h"
#include <iostream>
#include <set>
#include <fstream>
#include <string>

template <class T>
int reduce(T ar[], int n);
const int longN = 12;
const int stringN = 28;

int main()
{
	// с массивом long
	long arLong[longN]{ 1, 3, 5, 21, 3, 1, 9, 10, 21, 12, 100, 1 };
	std::cout << "Unsorted array size: " << longN << std::endl;
	std::cout << "Unsorted array: ";
	for (size_t i = 0; i < longN; i++) {
		std::cout << arLong[i] << ' ';
	}
	std::cout << std::endl << std::endl;
	int arLongSortedSize = reduce(arLong, longN);
	std::cout << "Sorted array size: " << arLongSortedSize << std::endl;
	std::cout << "Sorted array: ";
	for (size_t i = 0; i < arLongSortedSize; i++) {
		std::cout << arLong[i] << ' ';
	}

	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;

	// с массивом string
	std::ifstream file;
	file.open("Words.txt");
	std::string arString[stringN];
	for (int i = 0; i < stringN; i++) {
		file >> arString[i];
	}

	std::cout << "Unsorted array size: " << stringN << std::endl;
	std::cout << "Unsorted array: ";
	for (size_t i = 0; i < stringN; i++) {
		std::cout << arString[i] << ' ';
		if (i % 5 == 4) {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	int arStringSortedSize = reduce(arString, stringN);
	std::cout << "Sorted array size: " << arStringSortedSize << std::endl;
	std::cout << "Sorted array: ";
	for (size_t i = 0; i < arStringSortedSize; i++) {
		std::cout << arString[i] << ' ';
		if (i % 5 == 4) {
			std::cout << std::endl;
		}
	}
}


template <class T>
int reduce(T ar[], int n) {
	std::set<T> temp(ar, ar + n);// конструктор контейнере set сам отсортирует массив и удалит дупликаты
	int sortedSize = 0;
	for (auto i = temp.begin(); i != temp.end(); i++, sortedSize++) {
		ar[sortedSize] = *i;
	}
	/
	return sortedSize; // возвращает размер отсортированного массива.
}

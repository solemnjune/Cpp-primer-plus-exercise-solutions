#include "pch.h"
#include <iostream>
#include <set>

int reduce(long ar[], int n);
const int N = 12;

int main()
{
	long ar[N]{ 1, 3, 5, 21, 3, 1, 9, 10, 21, 12, 100, 1 };
	std::cout << "Unsorted array size: " << N << std::endl;
	std::cout << "Unsorted array: ";
	for (size_t i = 0; i < N; i++) {
		std::cout << ar[i] << ' ';
	}
	std::cout << std::endl << std::endl;
	int arSortedSize = reduce(ar, N);
	std::cout << "Sorted array size: " << arSortedSize << std::endl;
	std::cout << "Sorted array: ";
	for (size_t i = 0; i < arSortedSize; i++) {
		std::cout << ar[i] << ' ';
	}

}


int reduce(long ar[], int n) {
	std::set<long> temp(ar, ar+n);// конструктор контейнере set сам отсортирует массив и удалит дупликаты
	int sortedSize = 0;
	for (auto i = temp.begin(); i != temp.end(); i++, sortedSize++) {
		ar[sortedSize] = *i;
	}
	for (int i = sortedSize; i < n; i++) {// для безопасноти инициализируем остаток массива нулями. Именно поэтому были принято решение возвращать размер отсортированного массива
		ar[i] = 0;						 // не с помощью set.size(), а с помощью введения новой локальной переменной
	}
	return sortedSize; // возвращает размер отсортированного массива.
}

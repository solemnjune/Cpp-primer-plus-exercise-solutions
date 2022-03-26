#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const size_t sizeAr = 100000;

int main()
{
	srand(unsigned(time(NULL)));

	std::vector<int> vi0(sizeAr);
	for (size_t i = 0; i < sizeAr; i++) {
		vi0[i] = rand() % 1000;
	}
	std::vector<int> vi(vi0.begin(), vi0.end());
	std::list<int> li(vi0.begin(), vi0.end());

	clock_t start = clock();
	std::sort(vi.begin(), vi.end());
	clock_t end = clock();
	std::cout << "Sorting vi vector took: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

	start = clock();
	li.sort();
	end = clock();
	std::cout << "Sorting li list took: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

	std::copy(vi0.begin(), vi0.end(),li.begin());
	start = clock();
	std::copy(li.begin(), li.end(), vi.begin());
	std::sort(vi.begin(), vi.end());
	std::copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	std::cout << "Sorting li list using vi vector took: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

}

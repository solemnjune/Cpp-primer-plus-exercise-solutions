#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


std::vector<int> Lotto(int allNumbers, int winnerAmount);
void outint(int n) { std::cout << n << ' '; }

int main()
{
	srand(unsigned(time(NULL)));
	int allSpots = 0;
	int winnerSpots = 0;
	std::cout << "Enter the number of spots on the lottery card: ";
	std::cin >> allSpots;
	std::cout << "Enter the number of winner spots on the lottery card: ";
	std::cin >> winnerSpots;
	while (allSpots < 0 || winnerSpots < 0 || allSpots <= winnerSpots) {
		std::cout << "You have entered a wrong number!\n";
		std::cout << "Please, make sure that both numbers are greater, than zero, and that number of spots are greater than number of winner spots\n";
		std::cout << "Let's try again:\n";
		std::cout << "Enter the number of spots on the lottery card: ";
		std::cin >> allSpots;
		std::cout << "Enter the number of winner spots on the lottery card: ";
		std::cin >> winnerSpots;
	}

	std::vector<int> winners;
	winners = Lotto(allSpots, winnerSpots);
	std::cout << "Winner spots are: ";
	std::for_each(winners.begin(), winners.end(), outint);
	
}

std::vector<int> Lotto(int allNumbers, int winnerAmount) {
	std::vector <int> temp(allNumbers);
	for (int i = 0; i < allNumbers; i++) {
		temp[i] = i + 1;
	}
	std::random_shuffle(temp.begin(), temp.end());
	temp.erase(temp.begin() + winnerAmount, temp.end());
	return temp;
}

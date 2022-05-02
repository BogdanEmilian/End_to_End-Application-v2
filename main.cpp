#include <iostream>
#include "GameOfLife.hpp"

int main()
{
	int _n;

	std::cout << "Please enter th size of the map: \n";
	std::cin >> _n;

	GameOfLife::GameOfLife(_n);



	return 0;
}
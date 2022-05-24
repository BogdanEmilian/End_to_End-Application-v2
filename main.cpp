#include "pch.h"
#include <iostream>
#include "GameOfLife.hpp"


using namespace std;

TEST(Init, MapInit) {

	int n = 7;

	GameOfLife game(n);

	bool** map, ** testMap;

	testMap = new bool* [n];
	map = new bool* [n];

	for (int i = 0; i < n; ++i)
	{
		map[i] = new bool[n];
		testMap[i] = new bool[n];
	}
	

	game.setValue(1, 2, true);
	game.setValue(2, 1, true);
	game.setValue(2, 3, true);

	game.setValue(4, 3, true);
	game.setValue(4, 5, true);
	game.setValue(5, 4, true);

	game.setValue(5, 1, true);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			testMap[i][j] = false;
		}
	}

	testMap[1][2] = true;
	testMap[2][2] = true;
	testMap[3][2] = true;


	testMap[4][4] = true;
	testMap[5][4] = true;
	testMap[6][4] = true;

	map = game.getMap();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//ASSERT_EQ(map[i][j], testMap[i][j]);
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	game.evolvingStage();

	map = game.getMap();

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			//ASSERT_EQ(map[i][j], testMap[i][j]);
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//ASSERT_EQ(map[i][j], testMap[i][j]);
			cout << testMap[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; ++i)
	{
		delete[] testMap[i];
		delete[] map[i];

	}
	delete[] testMap;
	delete[] map;

}

int main()
{
	return	RUN_ALL_TESTS();
}
#include "pch.h"
#include <iostream>
#include "GameOfLife.hpp"


using namespace std;

TEST(Init, MapInit) {

	int n = 5;

	GameOfLife game(5);

	std::vector<std::vector<bool>> map, testMap;
	

	game.setValue(0, 1, true);
	game.setValue(1, 0, true);
	game.setValue(1, 2, true);

	game.setValue(3, 2, true);
	game.setValue(3, 4, true);
	game.setValue(4, 3, true);

	game.setValue(4, 0, true);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			testMap[i][j] = false;
		}
	}

	testMap[0][1] = true;
	testMap[1][1] = true;
	testMap[3][3] = true;
	testMap[4][3] = true;


	game.evolvingStage();

	map = game.getMap();

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			EXPECT_EQ(map[i][j], testMap[i][j]);
		}
	}
}

int main()
{
	return	RUN_ALL_TESTS();
	GameOfLife game(5);
	game.evolvingStage();
	return 0;
}
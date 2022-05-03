#include <iostream>
#include "GameOfLife.hpp"
#include "pch.h"

using namespace std;

TEST(Init, MapInit) {

	int n = 5;

	GameOfLife game(n);

	game.setValue(1, 2, true);
	game.setValue(2, 1, true);

	game.evolvingStage();

	ASSERT_TRUE(game.getValue(1, 1), true);
	ASSERT_TRUE(game.getValue(2, 2), true);
	ASSERT_TRUE(game.getValue(1, 2), false);
	ASSERT_TRUE(game.getValue(2, 1), false);
}

int main()
{
	/*
	int n=5;

	GameOfLife game(n);

	game.setValue(1, 1, true);
	game.setValue(1, 2, true);
	game.setValue(2, 1, true);

	cout << "Initial map:\n";

	game.printMap();
	game.evolvingStage();

	cout << "Final map:\n";

	game.printMap();
	*/
	return	RUN_ALL_TESTS();
}
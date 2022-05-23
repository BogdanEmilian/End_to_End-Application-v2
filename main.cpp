#include "pch.h"
#include <iostream>
#include "GameOfLife.hpp"


using namespace std;

TEST(Init, MapInit) {

	int n = 5;

	GameOfLife game(5);

	game.setValue(1, 2, true);
	game.setValue(2, 1, true);

	game.evolvingStage();

	ASSERT_TRUE(game.getValue(1, 1));
	ASSERT_TRUE(game.getValue(2, 2));
	ASSERT_FALSE(game.getValue(1, 2));
	ASSERT_FALSE(game.getValue(2, 1));
}

int main()
{
	return	RUN_ALL_TESTS();
	GameOfLife game(5);
	game.evolvingStage();
	return 0;
}
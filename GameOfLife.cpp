#include "pch.h"
#include "GameOfLife.hpp"

GameOfLife::GameOfLife(int size)
{
	_n = size;

	for (int i = 0; i < _n; ++i) {
		for (int j = 0; j < _n; j++) {
			_map[i][j] = new bool[_n];
		}
	}
}

void GameOfLife::evolvingStage()
{
	bool _tempMap;
	int _neighbour;

	//Center of the matrix scanning
	for (int y = 1; y < _n - 1; y++)
	{
		for (int x = 1; x < _n - 1; x++)
		{
			_neighbour = 0;

			if (_map[x - 1][y - 1] == true)
			{
				_neighbour++;
			}
			if (_map[x][y - 1] == true)
			{
				_neighbour++;
			}
			if (_map[x + 1][y - 1] == true)
			{
				_neighbour++;
			}
			if (_map[x - 1][y] == true)
			{
				_neighbour++;
			}
			if (_map[x + 1][y] == true)
			{
				_neighbour++;
			}
			if (_map[x - 1][y + 1] == true)
			{
				_neighbour++;
			}
			if (_map[x][y + 1] == true)
			{
				_neighbour++;
			}
			if (_map[x + 1][y + 1] == true)
			{
				_neighbour++;
			}
			/*
			if (_neighbour >= 3)
			{
				_tempMap[x][y] = true;	//alive cell
			}
			else
			{
				_tempMap[x][y] = false;	//dead cell
			}
			*/
		}
	}
}

bool** GameOfLife::getMap() {
	return _map;
}

void GameOfLife::setValue(int x, int y, bool v)
{
	/* int neighbour = 0;

	if ((_map[i - 1][j - 1] == true) && (i - 1 >= 0) && (j - 1 >= 0))
		neighbour++;

	if ((_map[i][j - 1] == true) && (j - 1 >= 0))
		neighbour++;

	if ((_map[i + 1][j - 1] == true) && (i + 1 < _n) && (j - 1 >= 0))
		neighbour++;

	if ((_map[i - 1][j] == true) && (i - 1 >= 0))
		neighbour++;

	if ((_map[i + 1][j] == true) && (i + 1 < _n))
		neighbour++;

	if ((_map[i - 1][j + 1] == true) && (i - 1 >= 0) && (j + 1 < _n))
		neighbour++;

	if ((_map[i + 1][j + 1] == true) && (i + 1 < _n) && (j + 1 < _n))
		neighbour++;

	if ((_map[i][j + 1] == true) && (j + 1 < _n))
		neighbour++;
		*/
	_map[x][y] = v;
}

void GameOfLife::setGlider(int x, int y)
{
	setValue(x + 1, y, true);
	setValue(x + 2, y + 1, true);
	setValue(x, y + 2, true);
	setValue(x + 1, y + 2, true);
	setValue(x + 2, y + 2, true);
}

void GameOfLife::setBlock(int x, int y)
{
	setValue(x, y, true);
	setValue(x, y + 1, true);
	setValue(x + 1, y, true);
	setValue(x + 1, y + 1, true);

}

void GameOfLife::setGliderGun(int x, int y)
{
	//https://en.wikipedia.org/wiki/Gun_(cellular_automaton)
}

void GameOfLife::printMap()
{
	for (int x = 0; x < _n; x++)
	{
		for (int y = 0; y < _n; y++)
		{
			cout << _map[x][y] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}

bool GameOfLife::getValue(int x, int y)
{
	return _map[x][y];
}

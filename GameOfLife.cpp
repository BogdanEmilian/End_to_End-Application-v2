#include "pch.h"
#include "GameOfLife.hpp"

GameOfLife::GameOfLife(int size)
{
	_n = size;

	bool** _map = new bool* [_n];

	for (int i = 0; i < _n; ++i) 
	{
		_map[i] = new bool[_n];
	}
}

void GameOfLife::evolvingStage()
{
	_tempMap = new bool* [_n];
	int _neighbour;

	for (int i = 0; i < _n; ++i)
	{
		_tempMap[i] = new bool[_n];
	}

	//Center of the matrix scanning
	for (int y = 1; y < _n - 1; y++)
	{
		for (int x = 1; x < _n - 1; x++)
		{
			/*
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
			
			if (_neighbour >= 3)
			{
				_tempMap[x][y] = true;	//alive cell
			}
			else
			{
				_tempMap[x][y] = false;	//dead cell
			}
			*/

			setValue(x, y);
			
		}
	}

	memcpy(_map, _tempMap, sizeof(_map));

	for (int i = 0; i < _n; ++i)
	{
		delete[] _tempMap[i];
	}
	delete[] _tempMap;
}

bool** GameOfLife::getMap() {
	return _map;
}

void GameOfLife::setValue(int x, int y)
{
	int _neighbour = 0;

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

	if (_neighbour >= 2 && _neighbour <= 3 && _map[x][y] == true)
	{
		_tempMap[x][y] = true;	//alive cell
	}
	else if(_neighbour == 3 && _map[x][y] == false)
	{
		_tempMap[x][y] = true;	//alive cell
	}
	else
	{
		_tempMap[x][y] = false;	//dead cell
	}

	//_map[x][y] = v;
}

void GameOfLife::setValue(int x, int y, bool v)
{
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

GameOfLife::~GameOfLife()
{
	for (int i = 0; i < _n; ++i)
	{
		delete[] _map[i];
	}
	delete[] _map;
}

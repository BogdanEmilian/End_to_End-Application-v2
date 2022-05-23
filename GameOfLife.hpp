#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

#include <string.h>
#include <stdlib.h>
#include "pch.h"	//TEST can't be in a function

using namespace std;

class GameOfLife
{
public:
	GameOfLife(int);			//initialization
	void evolvingStage();		//a step in the evolution
	void setValue(int, int, bool);
	void setGlider(int, int);
	bool getMap();
	void setBlock(int, int);
	void setGliderGun(int, int);
	void printMap();
	bool getValue(int, int);

private:
	bool _map[500][500];
	int _n;

};

#endif
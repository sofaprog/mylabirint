#pragma once

#include "Cell.h"
#include "Hero.h"
#include <iostream>
enum Action {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

using namespace std;
class Game {
	int h;
	int w;
	Cell **labirint;
	//Cell labirint[LAB_H][LAB_W];
	Hero hero;
	void setHeroPosition(int i, int j);
public:
	Game(const Game& game);
	Game();
	~Game();
	void move(Action act);
	friend ostream& operator << (ostream& out, Game& g);
};
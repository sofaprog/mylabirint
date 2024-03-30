#pragma once
#include "Hero.h"
#include <iostream>

using namespace std;
class Cell {
	char val;
	Hero* hero;
public:
	char getVal() {
		return val;
	};
	Cell();
	Cell(Hero* _hero);
	Cell(char _val);

	void setHero(Hero* _hero);
	friend ostream& operator << (ostream& out, Cell& c);
	bool haveHero() {
		return hero != nullptr;
	}
	bool operator+(Cell c);
};

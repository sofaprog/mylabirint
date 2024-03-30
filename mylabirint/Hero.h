#pragma once
#include <iostream>

using namespace std;
class Hero {
	int i, j;
public:

	int getI() { return i; };
	int getJ() { return j; };

	Hero(int _i = 0, int _j = 0) {
		i = _i;
		j = _j;
	};

	void move(int _i, int _j) {
		i = _i;
		j = _j;
	};

	friend ostream& operator << (ostream& out, Hero& h);
};
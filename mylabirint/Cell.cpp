#include "Cell.h"
#include <iostream>

Cell::Cell() {
	hero = nullptr;
	val = ' ';
}

Cell::Cell(Hero* _hero) {
	hero = _hero;
	val = ' ';
}

Cell::Cell(char _val) {
	hero = nullptr;
	val = _val;
}

void Cell::setHero(Hero* _hero) {
	hero = _hero;
}

ostream& operator << (ostream& out, Cell& c) {
	if (c.haveHero()) {
		out << "@";
	}
	else {
		out << c.getVal();
	}
	return out;
}

bool Cell::operator + (Cell c) {
	if (c.getVal() == '.') {
		return true;
	}

	if (c.getVal() == '#') {
		return false;
	}
	return false;
}
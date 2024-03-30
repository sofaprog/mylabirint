#include "Hero.h"
#include <iostream>

using namespace std;
/*void Hero::print() {
	std::cout << "@";
}*/

ostream& operator << (ostream& out, Hero& h) {
	out << "@";
	return out;
}
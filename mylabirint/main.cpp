#include <iostream>
#include "Game.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

void f(Game g) {}

int main() {
	setlocale(LC_ALL, "ru");
	Game g;

	f(g);

	unsigned char val = 0;
	while (val != 27) {
		system("color 50");
		system("cls");
		cout << g;

		val = _getch();
		if (val == 224) {
			val = _getch();
		}

		switch (val) {
		case 80:
			g.move(DOWN);
			break;
		case 72:
			g.move(UP);
			break;
		case 77:
			g.move(RIGHT);
			break;
		case 75:
			g.move(LEFT);
			break;
		}
		//printf("%u \n", val);
		//return 0;
	}
	return 0;
}
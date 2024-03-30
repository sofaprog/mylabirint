#include <iostream>
#include "Game.h"
#include <stdlib.h> 
#include <fstream>
//лабиринт с помощью динамической памяти,без LAB_H,LAB_W
void Game::setHeroPosition(int i, int j) {
	if (((i < 0) || (j < 0) || (i >= h) || (j >= w))) {
		return;
	}

	else {


		if (labirint[hero.getI()][hero.getJ()] + labirint[i][j]) {
			labirint[hero.getI()][hero.getJ()].setHero(nullptr);
			labirint[i][j].setHero(&hero);
			hero.move(i, j);
		}
	}
}
//добавлено чтение из файла
Game::Game(const Game& game) {
	 h=game.h;
	 w=game.w;
	 hero=game.hero;
	 labirint = new Cell * [h];
	 for (int i = 0; i < h; i++) {
		 labirint[i] = new Cell[w];
		 for (int j = 0; j < w; j++) {
			 labirint[i][j] = game.labirint[i][j];
		 }
	 }
}
Game::Game() {
	ifstream file("labirint.txt");
	file >> w;
	file >> h;
	labirint = new Cell * [h];
	for (int i = 0; i < h; i++) {
		labirint[i] = new Cell[w];
		for (int j = 0; j < w; j++) {
			char c;
			file >> c;
			labirint[i][j] = c;
		}
	}
	setHeroPosition(0, 0);
}
//деструктор,нужно добавить контруктор копирования
Game::~Game() {
	for (int i = 0; i < h; i++) {
		delete[] labirint[i];
	}
	delete[] labirint;
}

void Game::move(Action act) {
	int pi = hero.getI();
	int pj = hero.getJ();

	switch (act) {
	case UP:
		setHeroPosition(pi - 1, pj);
		break;
	case DOWN:
		setHeroPosition(pi + 1, pj);
		break;
	case RIGHT:
		setHeroPosition(pi, pj + 1);
		break;
	case LEFT:
		setHeroPosition(pi, pj - 1);
		break;
	}
}
//Перегрузка << для вывода на экран
ostream& operator << (ostream& out, Game& g) {
	int ip = g.hero.getI(), jp = g.hero.getJ();

	int r = 5;

	for (int i = ip - r; i <= ip + r; i++) {
		for (int j = jp - r; j <= jp + r; j++) {
			if ((i < 0) || (j < 0) || (i >= g.h) || (j >= g.w)) {
				out << '/';
			}
			else
				out << g.labirint[i][j];
		}

		out << '\n';
	}

	return out;
}
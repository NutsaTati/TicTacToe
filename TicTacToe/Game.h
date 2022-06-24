#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Game.h"
using namespace std;
using namespace sf;

char game[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
int game_x[9] = { 27,227,410,27,227,410,27,227,410 };
int game_y[9] = { 40,40,40,220,220,220,420,420,420 };

class GamePlay
{

private:

	char t = 'N';
	int check_o() {

		char a = game[0];

		for (int i = 1; i < 9; i++) {
			if (a == game[i] && (i + 1) != 3 && (i + 1) != 6 && isdigit(game[i + 1])) { return (i + 1); }
			else a = game[i];

		}



		for (int i = 0; i < 9; i++) {

			if (game[i] == game[i + 3]) {

				if (isdigit(game[i + 6])) return i + 6;

				else if (isdigit(game[i - 3])) return i - 3;

			}

		}



		return 11;
	}
	void o_turn() {
		int r = 1 + (rand() % 9);


		bool tie = true;
		for (int i = 0; i < 9; i++) {
			if (isdigit(game[i])) tie = false;
		}

		if (tie == true) {
			t = 't'; return;
		}
		if (check_o() != 11)r = check_o();
		else {
			while (!isdigit(game[r]))r = 1 + (rand() % 9);
		}
		game[r] = 'O';



	}





public:

	char check_for_winner() {

		if (game[0] == game[1] && game[0] == game[2]) return game[2];
		if (game[3] == game[4] && game[3] == game[5]) return game[5];
		if (game[6] == game[7] && game[6] == game[8]) return game[8];
		if (game[0] == game[3] && game[0] == game[6]) return game[6];
		if (game[1] == game[4] && game[4] == game[7]) return game[7];
		if (game[2] == game[5] && game[5] == game[8]) return game[8];
		if (game[0] == game[4] && game[4] == game[8]) return game[8];
		if (game[2] == game[4] && game[4] == game[6]) return game[6];
		return t;


	}
	void input(int x, int y) {


		if (x < 205) {
			if (y < 200 && isdigit(game[0])) { game[0] = 'X'; o_turn(); }
			else if (y > 200 && y < 395 && isdigit(game[3])) { game[3] = 'X'; o_turn(); }
			else if (y > 395 && isdigit(game[6])) { game[6] = 'X'; o_turn(); }
		}
		else if (x > 205 && x < 395) {
			if (y < 200 && isdigit(game[1])) { game[1] = 'X'; o_turn(); }
			else if (y > 200 && y < 395 && isdigit(game[4])) { game[4] = 'X'; o_turn(); }
			else if (y > 395 && isdigit(game[7])) { game[7] = 'X'; o_turn(); }

		}
		else if (x > 395) {
			if (y < 200 && isdigit(game[2])) { game[2] = 'X'; o_turn(); }
			else if (y > 200 && y < 395 && isdigit(game[5])) { game[5] = 'X'; o_turn(); }
			else if (y > 395 && isdigit(game[8])) { game[8] = 'X'; o_turn(); }

		}
	
	}
	void reset_game()
	{
		t = 'N';
		winner = 'N';
		for (int i = 0; i < 9; i++) {
			game[i] = i + '0';
		}
	}
	char winner = check_for_winner();

};


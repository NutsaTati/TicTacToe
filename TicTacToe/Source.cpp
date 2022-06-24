#include "Game.h"
RenderWindow win(VideoMode(600, 600), "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);

bool endscreen = false;

int main(){
	

	// LOAD IMAGES

	Texture background;
	Texture x_texture;
	Texture o_texture;
	Texture won; Texture lost; Texture tie;

	if (!x_texture.loadFromFile("assets/x.png"))cout << "X not found" << endl;
	Sprite X;
	if (!background.loadFromFile("assets/background.png"))cout << "B not found" << endl;
	Sprite Background;
	if (!o_texture.loadFromFile("assets/O.png"))cout << "O not found" << endl;
	Sprite O;
	if (!won.loadFromFile("assets/YOU_WON.png"))cout << "YOU_WON not found" << endl;
	Sprite Won;
	if (!lost.loadFromFile("assets/YOU_LOST.png"))cout << "YOU_LOST not found" << endl;
	Sprite Lost;
	if (!tie.loadFromFile("assets/TIE.png"))cout << "TIE not found" << endl;
	Sprite Tie;

	Background.setTexture(background);
	X.setTexture(x_texture);
	O.setTexture(o_texture);
	Lost.setTexture(lost); 	Won.setTexture(won); Tie.setTexture(tie);



	X.scale(Vector2f(0.25, 0.25));
	O.scale(Vector2f(0.25, 0.25));

	// END LOADING IMAGES

	GamePlay gameplay;
	int turn = 0;
	endscreen = false;

	
	while (win.isOpen()) {

		char winner = gameplay.check_for_winner();

		Event e;


		

		while (win.pollEvent(e)) {
			Vector2i mouse_pos = Mouse::getPosition(win);
			int x = mouse_pos.x, y = mouse_pos.y;
			switch (e.type) {
			case Event::Closed:
				win.close();
				break;
			case Event::KeyPressed:
				if(e.key.code == Keyboard::Escape)
					win.close();
					break;
	
			case Event::MouseButtonPressed:
				if (endscreen) {

					if (x > 152 && x < 456 && y >297 && y < 376) {
						gameplay.reset_game();

						main();
						
					}
					else if (x > 152 && x < 456 && y>393 && y < 470) {
						win.close();
					}
				}
				cout << "Mouse button pressed" << endl;
				if (winner == 'N' && !endscreen) { 
					Vector2i mouse_pos = Mouse::getPosition(win);
					gameplay.input(mouse_pos.x, mouse_pos.y);break;
				}
			}
	}
		// DISPLAYING THE GAME


		if (winner != 'N') {
			win.clear();
			win.draw(Background);
			if (turn == 0) {
				for (int i = 0; i < 9; i++) {
					if (game[i] == 'X') {
						X.setPosition(Vector2f(game_x[i], game_y[i]));
						win.draw(X);
						turn++;


					}if (game[i] == 'O') {
						O.setPosition(Vector2f(game_x[i], game_y[i]));
						win.draw(O);
						turn++;


					}
				}
				win.display();
				endscreen = true;
				sleep(sf::seconds(0.5));

			}
			else {

				if (winner == 'X')win.draw(Won);
				else if (winner == 'O')win.draw(Lost);
				else win.draw(Tie);
				win.display();
			}

		}
		else {

			win.clear();
			win.draw(Background);

			for (int i = 0; i < 9; i++) {
				if (game[i] == 'X') {
					X.setPosition(Vector2f(game_x[i], game_y[i]));
					win.draw(X);
				}if (game[i] == 'O') {
					O.setPosition(Vector2f(game_x[i], game_y[i]));
					win.draw(O);
				}
			}
			win.display();
		}
	}
}
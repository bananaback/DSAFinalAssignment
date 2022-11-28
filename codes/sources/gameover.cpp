#include <iostream>
#include "../headers/gameover.h"
#include "../headers/gamestate.h"
#include "../headers/button.h"
//#include "../headers/game.h"
GameOver::GameOver(Game& game) {
	_name = "gameover";
	_gameOverText.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::FONT_CREDIT]);
	_gameOverText.setString("GAME OVER");
	_gameOverText.setFillColor(sf::Color::Black);
	_gameOverText.setScale(sf::Vector2f(5.f, 5.f));
	_gameOverText.setPosition(sf::Vector2f(370.f, 100.f));

	_btns.push_back(std::make_shared<Button>(680, 380, 100, 46, "tryagain"));
	_btns.push_back(std::make_shared<Button>(680, 515, 100, 46, "backtomain"));
	_btns.push_back(std::make_shared<Button>(680, 650, 100, 46, "giveup"));
}

GameOver::~GameOver() {

}

void GameOver::handleEvents(Game& game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Space) {
				game.changeState("gameplay", 0, 0);
			}
		}
	}
	if (pEvent.type == sf::Event::MouseButtonReleased) {
		if (pEvent.mouseButton.button == sf::Mouse::Left) {
			for (size_t i = 0; i < _btns.size(); i++) {
				if (_btns[i]->checkHover(game)) {
					if (_btns[i]->getName() == "tryagain") game.changeState("gameplay", 0, 0);
					if (_btns[i]->getName() == "giveup") game.setRunning(false);
					if (_btns[i]->getName() == "backtomain") game.changeState("mainmenu", 0, 0);
				}
			}
		}
	}
}

void GameOver::update(Game& game) {
	for (size_t i = 0; i < _btns.size(); i++) {
		_btns[i]->update(game);
	}
}

void GameOver::render(Game& game) {
	_gameOverbg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::GAMEOVER_BG]);
	_gameOverbg.setScale(sf::Vector2f(12.f, 12.f));
	game._window.draw(_gameOverbg);
	game._window.draw(_gameOverText);

	for (size_t i = 0; i < _btns.size(); i++) {
		_btns[i]->draw(game);
	}
}

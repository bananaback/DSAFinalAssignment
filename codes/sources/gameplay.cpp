#include "../headers/gameplay.h"
#include <iostream>
GamePlay::GamePlay() {
    _monoFont.loadFromFile("assets/fonts/monogram-extended.ttf");

    _text.setFont(_monoFont);
    _text.setPosition(280, 350);
    _text.setString("Game play");
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::White);
    _text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _name = "gameplay";
	_grid = std::make_shared<Grid>();
} 

GamePlay::~GamePlay() {
    
}

void GamePlay::handleEvents(Game &game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Space) {
				game.changeState("mainmenu");
			}
		}
	}
}

void GamePlay::update(Game &game) {

}

void GamePlay::render(Game &game) {
    game._window.draw(_text);
}

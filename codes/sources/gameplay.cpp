#include "../headers/gameplay.h"
#include <iostream>
#include "../headers/player.h"
GamePlay::GamePlay(Game &game) {

    _text.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
    _text.setPosition(280, 350);
    _text.setString("Game play");
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::White);
    _text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _name = "gameplay";


	_grid = std::make_shared<Grid>();
	std::shared_ptr<Player> player = std::make_shared<Player>(200.0, 200.0, 48, 42, game, _grid);
	_grid->add(player);
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
	_grid->updateCells(game);
}

void GamePlay::render(Game &game) {
    game._window.draw(_text);
	_grid->draw(game);
}

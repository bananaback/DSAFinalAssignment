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


	_grid = std::make_shared<Grid>(game);
	std::shared_ptr<Player> player = std::make_shared<Player>(200.0, 200.0, 48, 42, game, _grid);
	_grid->add(player);
	std::shared_ptr<Player> player2 = std::make_shared<Player>(250, 200.0, 48, 42, game, _grid);
	_grid->add(player2);
	std::shared_ptr<Player> player3 = std::make_shared<Player>(300, 150.0, 48, 42, game, _grid);
	_grid->add(player3);
	std::shared_ptr<Player> player4 = std::make_shared<Player>(200, 250.0, 48, 42, game, _grid);
	_grid->add(player4);
	std::shared_ptr<Player> player5 = std::make_shared<Player>(250, 300.0, 48, 42, game, _grid);
	_grid->add(player5);
	std::shared_ptr<Player> player6 = std::make_shared<Player>(300, 300.0, 48, 42, game, _grid);
	_grid->add(player6);
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
		if (pEvent.type == sf::Event::MouseButtonPressed) {
			if (pEvent.mouseButton.button == sf::Mouse::Left) {
				for (int i = 0; i < 9; i++) {
					for (int j = 0; j < 16; j++) {
						//std::shared_ptr<GameObject>_grid->mCells[i][j];
					}
				}
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

#include "../headers/gameplay.h"
#include "../headers/calculator.h"
#include <iostream>
GamePlay::GamePlay(Game &game) {

    _text.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
    _text.setPosition(280, 350);
    _text.setString("Game play");
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::White);
    _text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _name = "gameplay";
	
	_background.setSize(sf::Vector2f(16.0 * 96, 9.0 * 96));
	_background.setFillColor(sf::Color(9, 184, 0));
	// add player
	_map.playerList.push_back(std::make_shared<Player>(200, 200, 40, 60, 100, 100, game));
	// add some enemy
	addEnemy(game);
} 

void GamePlay::addEnemy(Game& game) {
	_map.enemyList.push_back(std::make_shared<Enemy>(100, 400, 50, 50, 80, 5, 100, game));
	_map.enemyList.push_back(std::make_shared<Enemy>(200, 800, 50, 50, 80, 5, 100, game));
	_map.enemyList.push_back(std::make_shared<Enemy>(300, 200, 50, 50, 80, 5, 100, game));
	_map.enemyList.push_back(std::make_shared<Enemy>(400, 100, 50, 50, 80, 5, 100, game));
}

GamePlay::~GamePlay() {
    
}

void GamePlay::addPlayerBullet(Game& game) {
	std::shared_ptr<Player> player = _map.playerList[0];
	// get the current mouse position in the window
	sf::Vector2i pixelPos = sf::Mouse::getPosition(game._window);
	float angle = angleCalc(player->getX()+player->getWidth()/2, player->getY() + player->getHeight()/2, pixelPos.x, pixelPos.y);
	_map.bulletList.push_back(std::make_shared<Bullet>(player->getX() + player->getWidth() / 2, player->getY() + player->getHeight() / 2, 10, 10, 400, 5, angle, game));
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
				addPlayerBullet(game);
			}
		}
	}
}

void GamePlay::update(Game &game) {
	_map.updateAll(game);
}

void GamePlay::render(Game &game) {
	game._window.draw(_background);
	_map.drawAll(game);
}

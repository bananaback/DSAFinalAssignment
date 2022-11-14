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

	// add player
	_map.playerList.push_back(std::make_shared<Player>(200, 200, 50, 50, 100, 100));
	// add some enemy
	int enemyNumber = 2;
	for (int i = 0; i < enemyNumber; i++) addEnemy();
} 

void GamePlay::addEnemy() {
	_map.enemyList.push_back(std::make_shared<Enemy>(100, 100, 50, 50, 80, 5, 100));
}

GamePlay::~GamePlay() {
    
}

void GamePlay::addPlayerBullet(Game& game) {
	std::shared_ptr<Player> player = _map.playerList[0];
	// get the current mouse position in the window
	sf::Vector2i pixelPos = sf::Mouse::getPosition(game._window);
	float angle = angleCalc(player->getX()+player->getWidth()/2, player->getY() + player->getHeight()/2, pixelPos.x, pixelPos.y);
	_map.bulletList.push_back(std::make_shared<Bullet>(player->getX() + player->getWidth() / 2, player->getY() + player->getHeight() / 2, 5, 5, 400, 5, angle));
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
	_map.drawAll(game);
}

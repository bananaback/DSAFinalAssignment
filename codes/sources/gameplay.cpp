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
	// init player health bar
	_playerHpBar.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::HEALTHBAR_FILL]);
	_playerHPBarBg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::HEALTHBAR]);
	_playerHPBarBg.setScale(sf::Vector2f(2.f, 2.f));
	_playerHPBarBg.setPosition(20, 20);

	_playerHpBar.setScale(sf::Vector2f(2.f, 2.f));
	_playerHpBar.setPosition(40, 35);

	for (int i = 0; i < 5; i++) {
		_map.wallList.push_back(std::make_shared<Wall>(400, 400+32*i, 32, 32, game));
	}
	for (int i = 0; i < 5; i++) {
		_map.wallList.push_back(std::make_shared<Wall>(400+32*i, 400 + 32 * 5, 32, 32, game));
	}
} 

void GamePlay::addEnemy(Game& game) {
	_map.enemyList.push_back(std::make_shared<Enemy>(100, 400, 50, 50, 40, 5, 100, game));
	_map.enemyList.push_back(std::make_shared<Enemy>(200, 800, 50, 50, 40, 5, 100, game));
	_map.enemyList.push_back(std::make_shared<Enemy>(300, 200, 50, 50, 40, 5, 100, game));
	_map.enemyList.push_back(std::make_shared<Enemy>(400, 100, 50, 50, 40, 5, 100, game));
}

void GamePlay::drawPlayerHealthBar(Game& game) {
	game._window.draw(_playerHPBarBg);
	game._window.draw(_playerHpBar);
}

GamePlay::~GamePlay() {
    
}

void GamePlay::addPlayerBullet(Game& game) {
	std::shared_ptr<Player> player = _map.playerList[0];
	// get the current mouse position in the window
	sf::Vector2i pixelPos = sf::Mouse::getPosition(game._window);
	float angle = calculateAngle(player->getX()+player->getWidth()/2, player->getY() + player->getHeight()/2, pixelPos.x, pixelPos.y);
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
	// update player healthbar
	_playerHpBar.setScale(sf::Vector2f(_map.playerList[0]->getHealth()/100*2, 1));
	_map.updateAll(game);
}

void GamePlay::render(Game &game) {
	game._window.draw(_background);
	_map.drawAll(game);
	drawPlayerHealthBar(game);
}

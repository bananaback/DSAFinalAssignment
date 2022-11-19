#include "../headers/gameplay.h"
#include "../headers/calculator.h"
#include <iostream>
#include "../headers/astar.h"
#include "../headers/astarboi.h"
#include "../headers/utility.h"


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
	_map.playerList.push_back(std::make_shared<Player>(200, 200, 40, 40, 100, 100, game));
	// add some enemy
	addEnemy(game);
	// init player health bar
	_playerHpBar.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::HEALTHBAR_FILL]);
	_playerHPBarBg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::HEALTHBAR]);
	_playerHPBarBg.setScale(sf::Vector2f(2.f, 2.f));
	_playerHPBarBg.setPosition(20, 20);

	_playerHpBar.setScale(sf::Vector2f(2.f, 2.f));
	_playerHpBar.setPosition(40, 35);

	std::string map1Path = "./data/map1.txt";
	readMap(map1Path, _currentBlockMap);
	
	for (size_t i = 0; i < _currentBlockMap.size(); i++) {
		for (size_t j = 0; j < _currentBlockMap[i].size(); j++) {
			if (_currentBlockMap[i][j] != 0) {
				_map.wallList.push_back(std::make_shared<Wall>(48 * j, 48 * i, 48, 48, game, _currentBlockMap[i][j]));
			}
		}
	}
} 

void GamePlay::addEnemy(Game& game) {
	_map.enemyList.push_back(std::make_shared<Enemy>(48*4+9, 48*4+9, 30, 30, 80, 5, 100, game));
	//_map.enemyList.push_back(std::make_shared<Enemy>(200, 700, 30, 30, 80, 5, 100, game));
	//_map.enemyList.push_back(std::make_shared<Enemy>(300, 200, 30, 30, 80, 5, 100, game));
	//_map.enemyList.push_back(std::make_shared<Enemy>(400, 100, 30, 30, 80, 5, 100, game));
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
			if (pEvent.key.code == sf::Keyboard::Up) {
				_map.enemyList[0]->setY(_map.enemyList[0]->getY() - 48);
				float pCenterX = _map.playerList[0]->getX() + _map.playerList[0]->getWidth() / 2;
				float pCenterY = _map.playerList[0]->getY() + _map.playerList[0]->getHeight() / 2;
				int currentPlayerPosInCellX = (int)std::floor(pCenterX / 48);
				int currentPlayerPosInCellY = (int)std::floor(pCenterY / 48);
				float enemyCenterX = _map.enemyList[0]->getX() + _map.enemyList[0]->getWidth() / 2;
				float enemyCenterY = _map.enemyList[0]->getY() + _map.enemyList[0]->getHeight() / 2;
				_map.enemyList[0]->_path.clear();
				//_map.enemyList[0]->_path = pathFinding(_currentBlockMap,
				//	std::make_pair((int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48)),
				//	std::make_pair(currentPlayerPosInCellY, currentPlayerPosInCellX));

				_map.enemyList[0]->_path = astar(_currentBlockMap,
					(int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48),
					currentPlayerPosInCellY, currentPlayerPosInCellX);
			}
			if (pEvent.key.code == sf::Keyboard::Down) {
				_map.enemyList[0]->setY(_map.enemyList[0]->getY() + 48);
				float pCenterX = _map.playerList[0]->getX() + _map.playerList[0]->getWidth() / 2;
				float pCenterY = _map.playerList[0]->getY() + _map.playerList[0]->getHeight() / 2;
				int currentPlayerPosInCellX = (int)std::floor(pCenterX / 48);
				int currentPlayerPosInCellY = (int)std::floor(pCenterY / 48);
				float enemyCenterX = _map.enemyList[0]->getX() + _map.enemyList[0]->getWidth() / 2;
				float enemyCenterY = _map.enemyList[0]->getY() + _map.enemyList[0]->getHeight() / 2;
				_map.enemyList[0]->_path.clear();
				//_map.enemyList[0]->_path = pathFinding(_currentBlockMap,
				//	std::make_pair((int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48)),
				//	std::make_pair(currentPlayerPosInCellY, currentPlayerPosInCellX));
				_map.enemyList[0]->_path = astar(_currentBlockMap,
					(int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48),
					currentPlayerPosInCellY, currentPlayerPosInCellX);
			}
			if (pEvent.key.code == sf::Keyboard::Left) {
				_map.enemyList[0]->setX(_map.enemyList[0]->getX() - 48);
				float pCenterX = _map.playerList[0]->getX() + _map.playerList[0]->getWidth() / 2;
				float pCenterY = _map.playerList[0]->getY() + _map.playerList[0]->getHeight() / 2;
				int currentPlayerPosInCellX = (int)std::floor(pCenterX / 48);
				int currentPlayerPosInCellY = (int)std::floor(pCenterY / 48);
				float enemyCenterX = _map.enemyList[0]->getX() + _map.enemyList[0]->getWidth() / 2;
				float enemyCenterY = _map.enemyList[0]->getY() + _map.enemyList[0]->getHeight() / 2;
				_map.enemyList[0]->_path.clear();
				//_map.enemyList[0]->_path = pathFinding(_currentBlockMap,
				//	std::make_pair((int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48)),
				//	std::make_pair(currentPlayerPosInCellY, currentPlayerPosInCellX));
				_map.enemyList[0]->_path = astar(_currentBlockMap,
					(int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48),
					currentPlayerPosInCellY, currentPlayerPosInCellX);
			}
			if (pEvent.key.code == sf::Keyboard::Right) {
				_map.enemyList[0]->setX(_map.enemyList[0]->getX() + 48);
				float pCenterX = _map.playerList[0]->getX() + _map.playerList[0]->getWidth() / 2;
				float pCenterY = _map.playerList[0]->getY() + _map.playerList[0]->getHeight() / 2;
				int currentPlayerPosInCellX = (int)std::floor(pCenterX / 48);
				int currentPlayerPosInCellY = (int)std::floor(pCenterY / 48);
				float enemyCenterX = _map.enemyList[0]->getX() + _map.enemyList[0]->getWidth() / 2;
				float enemyCenterY = _map.enemyList[0]->getY() + _map.enemyList[0]->getHeight() / 2;
				_map.enemyList[0]->_path.clear();
				//_map.enemyList[0]->_path = pathFinding(_currentBlockMap,
				//	std::make_pair((int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48)),
				//	std::make_pair(currentPlayerPosInCellY, currentPlayerPosInCellX));
				_map.enemyList[0]->_path = astar(_currentBlockMap,
					(int)std::floor(enemyCenterY / 48), (int)std::floor(enemyCenterX / 48),
					currentPlayerPosInCellY, currentPlayerPosInCellX);
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

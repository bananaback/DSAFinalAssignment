#include <iostream>
#include "../headers/gameplay.h"
#include "../headers/calculator.h"
#include "../headers/astar.h"
#include "../headers/astarboi.h"
#include "../headers/utility.h"
#include "../headers/medkit.h"
#include "../headers/cannonbullet.h"
#include "../headers/flamethrowerbullet.h"
#include "../headers/mgbullet.h"
#include "../headers/onionbullet.h"
#include "../headers/tomatobullet.h"
#include "../headers/catbullet.h"

GamePlay::GamePlay(Game& game) {

	_text.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
	_text.setPosition(280, 350);
	_text.setString("Game play");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	_name = "gameplay";

	_background.setSize(sf::Vector2f(16.0 * 96, 9.0 * 96));
	_background.setFillColor(sf::Color(9, 184, 0));
	
	// init player health bar
	_playerHpBar.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::HEALTHBAR_FILL]);
	_playerHPBarBg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::HEALTHBAR]);
	_playerHPBarBg.setScale(sf::Vector2f(2.f, 2.f));
	_playerHPBarBg.setPosition(20, 20);

	_playerHpBar.setScale(sf::Vector2f(2.f, 2.f));
	_playerHpBar.setPosition(40, 35);


	_currentLevel = 1; // load from .txt soon
	_endLevel = 10;

	//_map.collectableItemList.push_back(std::make_shared<Medkit>(200, 500, 32, 32, game));
	
	_map.build(game, _currentLevel);
	fadeInInit(game);
}

template <typename T>
void removeObjects(std::vector<std::shared_ptr<T>>& t_list) {
	auto it = t_list.end();
	while (it > t_list.begin()) {
		it--;
		*it = nullptr;
		it = t_list.erase(it);
	}
}

void GamePlay::fadeInInit(Game& game) {
	removeObjects(_flyingTextList);
	_state = "fadein";
	_timer = 0;
	_blX = 0;
	_brX = 16*48;
	_addReady = false;
	_addLevel = false;
	_addGo = false;
	
	_backgroundLeft.setPosition(_blX, 0);
	_backgroundLeft.setSize(sf::Vector2f(16.0f * 48, 18.0f * 48));
	_backgroundLeft.setFillColor(sf::Color(156, 250, 255));

	_backgroundRight.setPosition(_brX, 0);
	_backgroundRight.setSize(sf::Vector2f(16.0f * 48, 18.0f * 48));
	_backgroundRight.setFillColor(sf::Color(156, 250, 255));
	
	_blackCover.setPosition(0, 0);
	_blackCover.setSize(sf::Vector2f(32.0f * 48, 18.0f * 48));
	_blackCover.setFillColor(sf::Color::Black);
	_blackCoverOpacity = 255;
	
	
}

void GamePlay::fadeOutInit(Game& game) {
	removeObjects(_typingTextList);
	_state = "fadeout";
	_timer = 0;
	_blX = -16 * 48;
	_brX = 32 * 48;

	_addLevelComplete = false;
	_addContinue = false;

	_backgroundLeft.setPosition(_blX, 0);
	_backgroundLeft.setSize(sf::Vector2f(16.0f * 48, 18.0f * 48));
	_backgroundLeft.setFillColor(sf::Color(252, 145, 5));

	_backgroundRight.setPosition(_brX, 0);
	_backgroundRight.setSize(sf::Vector2f(16.0f * 48, 18.0f * 48));
	_backgroundRight.setFillColor(sf::Color(252, 145, 5));
}

void GamePlay::drawPlayerHealthBar(Game& game) {
	game._window.draw(_playerHPBarBg);
	game._window.draw(_playerHpBar);
}

GamePlay::~GamePlay() {

}

std::uniform_int_distribution<> flameSpawnDistrAngle(-25, 25); // define the range
std::uniform_int_distribution<> bulletTypeDistr(0, 2); // 3 types of matter bullet

void GamePlay::addPlayerBullet(Game& game) {
	if (_map.playerList.size() > 0) {
		std::shared_ptr<Player> player = _map.playerList[0];
		// get the current mouse position in the window
		sf::Vector2i pixelPos = sf::Mouse::getPosition(game._window);
		float angle = calculateAngle(player->getX() + player->getWidth() / 2, player->getY() + player->getHeight() / 2, pixelPos.x, pixelPos.y);
		if (player->getCurrentWeapon() == Player::CANNON) {
			_map.playerBulletList.push_back(std::make_shared<CannonBullet>(game, player->getX() + player->getWidth() / 2 - 17/2, player->getY() + player->getHeight()/2 - 17/2, 17, 17, angle));
		} else if (player->getCurrentWeapon() == Player::FLAMETHROWER) {
			for (int i = 0; i < 5; i++) {
				float flameSpawnRadius = 40;
				_map.playerBulletList.push_back(std::make_shared<FlameThrowerBullet>(game, player->getX() + player->getWidth() / 2 - 13.f / 2 + std::cos(angle)*flameSpawnRadius, player->getY() + player->getHeight() / 2 - 10 / 2 + std::sin(angle) * flameSpawnRadius, 13, 10, angle + flameSpawnDistrAngle(game.gen) / 180.f * (std::atan(1) * 4)));
			}
		} else if (player->getCurrentWeapon() == Player::MGGUN) {
			_map.playerBulletList.push_back(std::make_shared<MgBullet>(game, player->getX() + player->getWidth() / 2 - 11.f / 2, player->getY() + player->getHeight() / 2 - 8.f / 2, 11, 8, angle));
		} else if (player->getCurrentWeapon() == Player::MATTER) {
			int curr = bulletTypeDistr(game.gen);
			float spawnRadius = 30;
			float adjustX = std::cos(angle) * spawnRadius;
			float adjustY = std::sin(angle) * spawnRadius;
			if (curr == 0) {
				_map.playerBulletList.push_back(std::make_shared<OnionBullet>(game, player->getX() + player->getWidth() / 2 - 13.f + adjustX, player->getY() + player->getHeight() / 2 - 13.f + adjustY, 26, 26, angle));
			} else if (curr == 1) {
				_map.playerBulletList.push_back(std::make_shared<TomatoBullet>(game, player->getX() + player->getWidth() / 2 - 11.f + adjustX, player->getY() + player->getHeight() / 2 - 12.f + adjustY, 22, 24, angle));
			} else if (curr == 2) {
				_map.playerBulletList.push_back(std::make_shared<CatBullet>(game, player->getX() + player->getWidth() / 2 - 19.f + adjustX, player->getY() + player->getHeight() / 2 - 14.f + adjustY, 38, 28, angle));
			}
		}
	}
}

void GamePlay::handleEvents(Game& game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Space) {
				//game.changeState("mainmenu");
			}
			if (pEvent.key.code == sf::Keyboard::Enter) {
				fadeOutInit(game);
			}
			if (pEvent.key.code == sf::Keyboard::C) {
				_map.clear(game);
				if (_currentLevel != _endLevel)
				{
					_currentLevel++;
					_map.build(game, _currentLevel);
					fadeInInit(game);
				} else {
					game.changeState("ending", 1, 0);
				}
			}
			if (pEvent.key.code == sf::Keyboard::Num1) {
				_map.playerList[0]->setWeapon(Player::CANNON);
			}
			if (pEvent.key.code == sf::Keyboard::Num2) {
				_map.playerList[0]->setWeapon(Player::FLAMETHROWER);
			}
			if (pEvent.key.code == sf::Keyboard::Num3) {
				_map.playerList[0]->setWeapon(Player::MGGUN);
			}
			if (pEvent.key.code == sf::Keyboard::Num4) {
				_map.playerList[0]->setWeapon(Player::MATTER);
			}
		}
		if (pEvent.type == sf::Event::MouseButtonPressed) {
			if (pEvent.mouseButton.button == sf::Mouse::Left) {
				addPlayerBullet(game);
			}
		}
	}
}

void GamePlay::update(Game& game) {
	if (_state == "fadein") {
		_timer += game._dt;
		if (_addReady == false && _timer >= 1) {
			_flyingTextList.push_back(std::make_shared<FlyingText>(-100, 250, 200, 1200, "black", "READY", game));
			_addReady = true;
		}
		if (_addLevel == false && _timer >= 2) {
			_flyingTextList.push_back(std::make_shared<FlyingText>(-100, 250, 200, 1200, "black", "LEVEl "+std::to_string(_currentLevel), game));
			_addLevel = true;
		}
		if (_addGo == false && _timer >= 3) {
			_flyingTextList.push_back(std::make_shared<FlyingText>(-100, 250, 200, 1200, "black", "GO!", game));
			_addGo = true;
		}
		if (_timer >= 4) {
			_blX -= game._dt * 600;
			_brX += game._dt * 600;
		}
		_backgroundLeft.setPosition(_blX, 0);
		_backgroundRight.setPosition(_brX, 0);
		for (size_t i = 0; i < _flyingTextList.size(); i++) {
			_flyingTextList[i]->update(game);
		}
		if (_blackCoverOpacity > 0) {
			_blackCoverOpacity -= game._dt * 150;
		} else {
			_blackCoverOpacity = 0;
		}
		if (_timer > 5.5) {
			removeObjects(_flyingTextList);
			_state = "gameplay";
		}
		auto it = _flyingTextList.end();
		while (it > _flyingTextList.begin()) {
			it--;
			if ((*it)->isDestroyed()) {
				*it = nullptr;
				it = _flyingTextList.erase(it);
			}
		}
	} else if (_state == "gameplay") {
		// update player healthbar
		if (_map.playerList.size() >= 1) {
			_playerHpBar.setScale(sf::Vector2f(_map.playerList[0]->getHealth() / 100 * 2, 1));
		}
		
		_map.updateAll(game);
		if (_map.levelFinish) {
			fadeOutInit(game);
		}
	} else if (_state == "fadeout") {
		_timer += game._dt;
		if (_addLevelComplete == false && _timer >= 1) {
			_typingTextList.push_back(std::make_shared<TypingText>(200, 150, 150, 0.1, "LEVEL " + std::to_string(_currentLevel) + " COMPLETE", game));
			_addLevelComplete = true;
		}
		if (_addContinue == false && _timer >= 3) {
			_typingTextList.push_back(std::make_shared<TypingText>(350, 350, 100, 0.1, "PRESS C TO CONTINUE", game));
			_addContinue = true;
		}
		if (_blX < 0) {
			_blX += game._dt * 600;
		} else {
			_blX = 0;
		}
		if (_brX > 16 * 48) {
			_brX -= game._dt * 600;
		} else {
			_brX = 16 * 48;
		}
		_backgroundLeft.setPosition(_blX, 0);
		_backgroundRight.setPosition(_brX, 0);
		for (size_t i = 0; i < _typingTextList.size(); i++) {
			_typingTextList[i]->update(game);
		}
	}
}

void GamePlay::render(Game& game) {
	if (_state == "fadein") {
		game._window.draw(_background);
		_map.drawAll(game);
		drawPlayerHealthBar(game);
		game._window.draw(_backgroundLeft);
		game._window.draw(_backgroundRight);
		for (size_t i = 0; i < _flyingTextList.size(); i++) {
			_flyingTextList[i]->draw(game);
		}
		_blackCover.setFillColor(sf::Color(0, 0, 0, _blackCoverOpacity));
		game._window.draw(_blackCover);
	} else if (_state == "gameplay") {
		game._window.draw(_background);
		_map.drawAll(game);
		drawPlayerHealthBar(game);
	} else if (_state == "fadeout") {
		game._window.draw(_background);
		_map.drawAll(game);
		drawPlayerHealthBar(game);
		game._window.draw(_backgroundLeft);
		game._window.draw(_backgroundRight);
		for (size_t i = 0; i < _typingTextList.size(); i++) {
			_typingTextList[i]->draw(game);
		}
	}
}
// To do: build map and clear map properly
// add end game screen and saving 
// ask two teamates about map design
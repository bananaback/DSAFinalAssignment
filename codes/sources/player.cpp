#include <iostream>
#include <fstream>

#include "../headers/resource_allocator.h"
#include "../headers/player.h"
#include "../headers/gameobject.h"

Player::Player(float x, float y, float width, float height, float speed, float healthPoint, Game& game) : Character(x, y, width, height) {
	_speed = speed;
	_healthPoint = healthPoint;
	std::cout << "I'm player\n";

	float frameDuration = 0.1f;
	_assetWidth = 20;
	_assetHeight = 24;
	_scaleX = 3;
	_scaleY = 3;
	_angle = 0;
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::PLAYER_E], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "e"));//0
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::PLAYER_NE], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "ne"));//1
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::PLAYER_SE], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "se"));//2
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::PLAYER_N], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "n"));//3
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::PLAYER_S], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "s"));//4
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::PLAYER_SGUN], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "sgun"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::PLAYER_IDLE], 0, 0, _assetWidth, _assetHeight, 1, frameDuration, "idle"));
	_currentAnimation = 0;
	
	std::ifstream myScore("./data/score.txt");
	std::string currScore = "0";
	if (myScore.is_open()) {
		myScore >> currScore;
		_coin = std::stoi(currScore);
	} else {
		std::cout << "Can't not read score.txt";
	}
	myScore.close();
	_realCoin = _coin;
	_hurting = 0;
	_hurtTimer = 0;
	_appear = true;

	_weaponDisplayList.push_back(std::make_shared<Cannon>(game, 0, 0, 2));
	_weaponDisplayList.push_back(std::make_shared<FlameThrower>(game, 0, 0, 2));
	_weaponDisplayList.push_back(std::make_shared<MgGun>(game, 0, 0, 2));
	_weaponDisplayList.push_back(std::make_shared<Matter>(game, 0, 0, 2));
	
	_currentWeapon = 0;

	_coinAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::COIN_HUD], 2, 0, 16, 16, 4, 0.1, "coinhud");
	_coinScale = 2;
	_coinMinScale = 2;
	_scoreScale = 2;
	_scoreMinScale = 2;
	_increaseCoinReload = 0;

	_char.setTexture(*game.ra_ptr->_imageResources[IMAGE::IMG_FONT]);
	_char.setOrigin(10, 10);
}

int Player::getScore() {
	return _coin;
}

void Player::drawText(Game& game, float x, float y, std::string s, float scale) {
	for (int i = 0; i < s.length(); i++) {
		_char.setTextureRect(game.ra_ptr->_imgFontIntRects[game.ra_ptr->_charMapping[s[i]]]);
		_char.setPosition(x + i * 35, y);
		_char.setScale(sf::Vector2f(scale, scale));
		game._window.draw(_char);
	}
}

void Player::drawPlayerCoin(Game& game) {
	_coinAnimation->draw(game, 1300, 50, 0, _coinScale, _coinScale, 8, 8);
	drawText(game, 1350, 50, std::to_string(_realCoin), _scoreScale);
}

void Player::setWeapon(int c) {
	_currentWeapon = c;
}

int Player::getCurrentWeapon() {
	return _currentWeapon;
}

void Player::setX(float x) {
	_x = x;
}

void Player::setY(float y) {
	_y = y;
}

void Player::setCoin(int c) {
	_coin = c;
}
int Player::getCoin() {
	return _coin;
}

float Player::getHealth() {
	return _healthPoint;
}

void Player::setHealth(float h) {
	_healthPoint = h;
}

void Player::increaseCoin(int amount) {
	_coin += amount;
	_coinScale = 3;
	_scoreScale = 3;
}

void Player::increaseHealth(double regenValue) {
	_healthPoint += regenValue;
	if (_healthPoint > 100) _healthPoint = 100;
}

void Player::takeDamage(float d) {
	if (_hurting <= 0) {
		_healthPoint = _healthPoint - d;
		_hurting = 1;
	}
}

void Player::setUp(bool b) {
	canGoUp = b;
}

void Player::setDown(bool b) {
	canGoDown = b;
}

void Player::setLeft(bool b) {
	canGoLeft = b;
}

void Player::setRight(bool b) {
	canGoRight = b;
}

float Player::getSpeed() {
	return _speed;
}

Player::~Player() {
	moveVec.x = 0;
	moveVec.y = 0;
}

void Player::update(Game& game) {
	if (_healthPoint < 0) _healthPoint = 0;
	_hurtTimer += game._dt;
	if (_hurtTimer >= 0.05) {
		_hurtTimer = 0;
		_appear = !_appear;
	}
	if (_hurting >= 0) {
		_hurting -= game._dt;
	}
	else {
		_appear = true;
	}
	bool updateAnim = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canGoUp) {
		moveVec.y = -1;
		updateAnim = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canGoDown) {
		moveVec.y = 1;
		updateAnim = true;
	}
	else {
		moveVec.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canGoLeft) {
		moveVec.x = -1;
		updateAnim = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canGoRight) {
		moveVec.x = 1;
		updateAnim = true;
	}
	else {
		moveVec.x = 0;
	}
	_x += moveVec.x * _speed * game._dt;
	_y += moveVec.y * _speed * game._dt;

	if (updateAnim) _animations[_currentAnimation]->update(game._dt);

	sf::Vector2i mouse_pos = sf::Mouse::getPosition(game._window);
	_angle = std::atan2(-(mouse_pos.y - (_y + _width / 2)), -(mouse_pos.x - (_x + _height / 2))) * 180 / (std::atan(1) * 4);
	int a = std::floor((_angle + 180 + 22.5) / 45);
	_currentAnimation = _assetName[a];
	_weaponDisplayList[_currentWeapon]->update(game, _angle, _x + _width / 2, _y + _height / 2);


	if (std::abs(_angle) < 67.5) _scaleX = -3.f; else _scaleX = 3.f;

	_coinAnimation->update(game._dt);
	if (_coinScale > _coinMinScale) {
		_coinScale -= game._dt * 2;
	}
	else {
		_coinScale = _coinMinScale;
	}
	if (_scoreScale > _scoreMinScale) {
		_scoreScale -= game._dt * 5;
	}
	else {
		_scoreScale = _scoreMinScale;
	}

	_increaseCoinReload += game._dt;
	if (_increaseCoinReload >= 0.02) {
		_increaseCoinReload = 0;
		if (_realCoin < _coin) {
			_realCoin++;
			_scoreScale = 2.5;
		}
	}

	//if (_healthPoint <= 0) game.changeState("gameover", 1, 0);
}

void Player::draw(Game& game) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setOutlineColor(sf::Color::Blue);
	//rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	//game._window.draw(rectangle);
	if (_appear) {
		if (_angle >= 0) _weaponDisplayList[_currentWeapon]->draw(game);
		_animations[_currentAnimation]->_sprite.setPosition(_x + _width / 2, _y + _height / 2);
		_animations[_currentAnimation]->_sprite.setOrigin(_assetWidth / 2, _assetHeight / 2);
		_animations[_currentAnimation]->_sprite.setScale(_scaleX, _scaleY);
		game._window.draw(_animations[_currentAnimation]->_sprite);
		if (_angle < 0)  _weaponDisplayList[_currentWeapon]->draw(game);
	}
	//drawPlayerCoin(game);
}
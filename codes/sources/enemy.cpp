#include <iostream>

#include "../headers/enemy.h"
#include "../headers/gameobject.h"
#include "../headers/game.h"
#include "../headers/calculator.h"
#include "../headers/astar.h"
#include "../headers/utility.h"



Enemy::Enemy(float x, float y, float width, float height, float speed, float attackDamage, float healthPoint, Game& game) : Character(x, y, width, height) {
	_speed = speed;
	_attackDamage = attackDamage;
	_healthPoint = healthPoint;
	_angle = 0;
	_scaleX = 3.f;
	_scaleY = 3.f;

	float frameDuration = 0.1;
	_assetWidth = 16;
	_assetHeight = 16;
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SLIME_BACK], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "back"));//0
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SLIME_FRONT], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "front"));//1
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SLIME_SIDE], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "side"));//2
	//_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_N], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "explode"));//3
	_currentAnimation = 0;
}

Enemy::~Enemy() {
	std::cout << _healthPoint << " ";
	std::cout << "Enemy removed\n";
}

void Enemy::setX(float x) {
	_x = x;
}

void Enemy::setY(float y) {
	_y = y;
}

bool Enemy::isArrived(float x, float y) {
	float d = distance(x, y, _x + _width / 2, _y + _height / 2);
	if (d <= 5) return true;
	return false;
}

void Enemy::update(Game& game, float pX, float pY) {
	float xVel = 0;
	float yVel = 0;

	if (_path.size() >= 2) {
		int targetY = _path[1].first * 48 + 24;
		int targetX = _path[1].second * 48 + 24;
		_angle = calculateAngle(_x + _width / 2, _y + _height / 2, targetX, targetY);
		xVel = std::cos(_angle) * _speed * game._dt;
		yVel = std::sin(_angle) * _speed * game._dt;

		if (isArrived(targetX, targetY)) _path.erase(_path.begin() + 1);
	}


	if (_healthPoint <= 0) _isDestroyed = true;
	if ((xVel >= 0 && canGoRight) || (xVel < 0 && canGoLeft)) _x += xVel;
	if ((yVel >= 0 && canGoDown) || (yVel < 0 && canGoUp)) _y += yVel;

	if (std::abs(xVel) > std::abs(yVel)) {
		if (xVel >= 0) {
			_currentAnimation = 2;
			_scaleX = -3.f;
		}
		else {
			_currentAnimation = 2;
			_scaleX = 3.f;
		}
	}
	else {
		if (yVel >= 0) {
			_currentAnimation = 1;
		}
		else {
			_currentAnimation = 0;
		}
	}
	_animations[_currentAnimation]->update(game._dt);
}

void Enemy::draw(Game& game) {
	sf::RectangleShape rectangle;
	/*rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setOutlineColor(sf::Color::Yellow);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);
	*/
	_animations[_currentAnimation]->_sprite.setPosition(_x + _width / 2, _y + _height / 2);
	_animations[_currentAnimation]->_sprite.setOrigin(_assetWidth / 2, _assetHeight / 2);
	_animations[_currentAnimation]->_sprite.setScale(_scaleX, _scaleY);
	game._window.draw(_animations[_currentAnimation]->_sprite);

	sf::RectangleShape healthBar;
	healthBar.setSize(sf::Vector2f(70.0 * (_healthPoint / 100.0), 5));
	healthBar.setOutlineColor(sf::Color::Green);
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(_x - 10, _y - 15);
	game._window.draw(healthBar);
	//draw path
	for (size_t i = 0; i < _path.size(); i++) {
		rectangle.setPosition(sf::Vector2f(_path[i].second * 48, _path[i].first * 48));
		rectangle.setSize(sf::Vector2f(48.f, 48.f));
		rectangle.setFillColor(sf::Color(1, 0, 0, 30));
		rectangle.setOutlineColor(sf::Color(0, 0, 0, 255));
		rectangle.setOutlineThickness(2);
		game._window.draw(rectangle);
	}
}

float Enemy::getHealth() {
	return _healthPoint;
}

void Enemy::setHealth(float h) {
	_healthPoint = h;
}

void Enemy::takeDamage(float d) {
	_healthPoint -= d;
}

#include "../headers/player.h"
#include "../headers/gameobject.h"
#include <iostream>
Player::Player(float x, float y, float width, float height, float speed, float healthPoint, Game& game) : GameObject(x, y, width, height) {
	_speed = speed;
	_healthPoint = healthPoint;
	std::cout << "I'm player\n";

	float frameDuration = 0.1f;
	_assetWidth = 20;
	_assetHeight = 24;
	_scaleX = 3;
	_scaleY = 3;
	_angle = 0;
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_E], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "e"));//0
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_NE], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "ne"));//1
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_SE], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "se"));//2
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_N], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "n"));//3
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_S], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "s"));//4
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_SGUN], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "sgun"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::PLAYER_IDLE], 0, 0, _assetWidth, _assetHeight, 1, frameDuration, "idle"));
	_currentAnimation = 0;
	_coin = 0;
}
void Player::setCoin(int c) {
	_coin = c;
}
int Player::getCoin() {
	return _coin;
}

Player::~Player() {
	moveVec.x = 0;
	moveVec.y = 0;
}

void Player::update(Game& game) {
	bool updateAnim = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		moveVec.y = -1;
		updateAnim = true;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		moveVec.y = 1;
		updateAnim = true;
	} else {
		moveVec.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		moveVec.x = -1;
		updateAnim = true;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		moveVec.x = 1;
		updateAnim = true;
	} else {
		moveVec.x = 0;
	}
	_x += moveVec.x * _speed * game._dt;
	_y += moveVec.y * _speed * game._dt;

	if (updateAnim) _animations[_currentAnimation]->update(game._dt);

	sf::Vector2i mouse_pos = sf::Mouse::getPosition(game._window);
	_angle = std::atan2(-(mouse_pos.y - (_y + _width / 2)), -(mouse_pos.x - (_x + _height / 2))) * 180 / (std::atan(1) * 4);
	int a = std::floor((_angle + 180 + 22.5) / 45);
	_currentAnimation = _assetName[a];

	if (a == 0 || a == 8) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_SIDE]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 + 10, _y + _height / 2 + 5));
		_gun.setScale(sf::Vector2f(2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 17, 10));
	}
	else if (a == 1) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DIAGDOWN]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 + 8, _y + _height / 2 + 5));
		_gun.setScale(sf::Vector2f(2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 16, 13));
	}
	else if (a == 2) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DOWN]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 - 12, _y + _height / 2 + 10));
		_gun.setScale(sf::Vector2f(2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 12, 14));
	}
	else if (a == 3) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DIAGDOWN]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 - 6, _y + _height / 2 + 5));
		_gun.setScale(sf::Vector2f(-2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 16, 13));
	}
	else if (a == 4) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_SIDE]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 - 8, _y + _height / 2 + 5));
		_gun.setScale(sf::Vector2f(-2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 17, 10));
	}
	else if (a == 5) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DIAGUP]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 - 15, _y + _height / 2 - 10));
		_gun.setScale(sf::Vector2f(-2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 15, 13));
	}
	else if (a == 6) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_UP]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 - 12, _y + _height / 2 - 14));
		_gun.setScale(sf::Vector2f(2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 12, 14));
	}
	else if (a == 7) {
		_gun.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DIAGUP]);
		_gun.setPosition(sf::Vector2f(_x + _width / 2 + 15, _y + _height / 2 - 10));
		_gun.setScale(sf::Vector2f(2.0, 2.0));
		_gun.setTextureRect(sf::IntRect(0, 0, 15, 13));
	}


	if (std::abs(_angle) < 67.5) _scaleX = -3.f; else _scaleX = 3.f;
}

void Player::draw(Game& game) {
	/*sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);*/

	if (_angle >= 0) game._window.draw(_gun);

	_animations[_currentAnimation]->_sprite.setPosition(_x + _width / 2, _y + _height / 2);
	_animations[_currentAnimation]->_sprite.setOrigin(_assetWidth / 2, _assetHeight / 2);
	_animations[_currentAnimation]->_sprite.setScale(_scaleX, _scaleY);
	game._window.draw(_animations[_currentAnimation]->_sprite);
	if (_angle < 0) game._window.draw(_gun);
	sf::RectangleShape healthBar;
	healthBar.setSize(sf::Vector2f(70.0/100*_healthPoint, 5));
	healthBar.setOutlineColor(sf::Color::Green);
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(_x - 10, _y - 15);
}
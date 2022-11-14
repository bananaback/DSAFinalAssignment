#include "../headers/player.h"
#include "../headers/gameobject.h"
#include <iostream>
Player::Player(float x, float y, float width, float height, float speed, float healthPoint) : GameObject(x, y, width, height) {
	_speed = speed;
	_healthPoint = healthPoint;
	std::cout << "I'm player\n";
}

Player::~Player() {
	moveVec.x = 0;
	moveVec.y = 0;
}

void Player::update(Game& game) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		moveVec.y = -1;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		moveVec.y = 1;
	} else {
		moveVec.y = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		moveVec.x = -1;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		moveVec.x = 1;
	} else {
		moveVec.x = 0;
	}
	_x += moveVec.x * _speed * game._dt;
	_y += moveVec.y * _speed * game._dt;
}

void Player::draw(Game& game) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);

	sf::RectangleShape healthBar;
	healthBar.setSize(sf::Vector2f(70.0/100*_healthPoint, 5));
	healthBar.setOutlineColor(sf::Color::Green);
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(_x - 10, _y - 15);
	//game._window.draw(healthBar);
}
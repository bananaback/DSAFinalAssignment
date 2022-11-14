#include "../headers/enemy.h"
#include "../headers/gameobject.h"
#include "../headers/game.h"
#include "../headers/calculator.h"
#include <iostream>
Enemy::Enemy(float x, float y, float width, float height, float speed, float attackDamage, float healthPoint) : GameObject(x, y, width, height) {
	_speed = speed;
	_attackDamage = attackDamage;
	_healthPoint = healthPoint;
	_angle = 0;
}

Enemy::~Enemy() {
	std::cout << "Enemy removed";
}

void Enemy::update(Game& game, float pX, float pY) {
	_angle = angleCalc(_x+_width/2, _y+_height/2, pX, pY);
	_x += std::cos(_angle)*_speed*game._dt;
	_y += std::sin(_angle)*_speed*game._dt;
	if (_healthPoint <= 0) _isDestroyed = true;
}

void Enemy::draw(Game& game) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setOutlineColor(sf::Color::Yellow);
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);

	sf::RectangleShape healthBar;
	healthBar.setSize(sf::Vector2f(70.0 * (_healthPoint/100.0), 5));
	healthBar.setOutlineColor(sf::Color::Green);
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(_x - 10, _y - 15);
	//game._window.draw(healthBar);
}

float Enemy::getHealth()
{
	return _healthPoint;
}

void Enemy::setHealth(float h)
{
	_healthPoint = h;
}

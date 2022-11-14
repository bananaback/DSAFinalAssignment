#include "../headers/bullet.h"
#include "../headers/gameobject.h"
#include <iostream>
Bullet::Bullet(float x, float y, float width, float height, float speed, float damage, float angle) : GameObject(x, y, width, height) {
	_speed = speed;
	_damage = damage;
	_angle = angle;
	_timer = 0;
	_lifeTime = 1;
	std::cout << "Im bullet\n";
}

Bullet::~Bullet() {
	std::cout << "Bullet removed\n";
}

void Bullet::update(Game& game) {
	_x += std::cos(_angle)*_speed*game._dt;
	_y += std::sin(_angle)*_speed*game._dt;
	_timer += game._dt;
	if (_timer > _lifeTime) {
		_isDestroyed = true;
	}
}

void Bullet::draw(Game& game) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setOutlineColor(sf::Color::Green);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);
}

float Bullet::getDamage() {
	return _damage;
}
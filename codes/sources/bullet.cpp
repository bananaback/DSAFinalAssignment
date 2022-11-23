#include <iostream>
#include "../headers/bullet.h"
#include "../headers/gameobject.h"

Bullet::Bullet(float x, float y, float width, float height, float speed, float damage, float angle, Game& game) : GameObject(x, y, width, height) {
	_speed = speed;
	_damage = damage;
	_angle = angle;
	_timer = 0;
	_lifeTime = 1;
	std::cout << "Im bullet\n";

	_assetWidth = 17;
	_assetHeight = 17;
	_img.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNONBALL]);
}

Bullet::~Bullet() {
	std::cout << "Bullet removed\n";
}

void Bullet::update(Game& game) {
	_x += std::cos(_angle) * _speed * game._dt;
	_y += std::sin(_angle) * _speed * game._dt;
	_timer += game._dt;
	if (_timer > _lifeTime) {
		_isDestroyed = true;
	}
}

void Bullet::draw(Game& game) {
	/*sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setOutlineColor(sf::Color::Green);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);
	*/
	_img.setPosition(_x + _width / 2, _y + _height / 2);
	_img.setOrigin(_assetWidth / 2, _assetHeight / 2);
	game._window.draw(_img);
}

float Bullet::getDamage() {
	return _damage;
}
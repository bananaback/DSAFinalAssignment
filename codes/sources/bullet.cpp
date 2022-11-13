#include "../headers/bullet.h"

Bullet::Bullet(float x, float y, float width, float height, float speed, float damage) : GameObject(x, y) {
	_width = width;
	_height = height;
	_speed = speed;
	_damage = damage;
}

Bullet::~Bullet() {
	
}

void Bullet::update(Game& game) {

}

void Bullet::draw(Game& game) {

}
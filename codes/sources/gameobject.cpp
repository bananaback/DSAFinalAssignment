#include "../headers/gameobject.h"

GameObject::GameObject(float x, float y) {
	_x = x;
	_y = y;
	_prev = nullptr;
	_next = nullptr;
	_dead = false;
}

float GameObject::getX() {
	return _x;
}

float GameObject::getY() {
	return _y;
}

float GameObject::getWidth()
{
	return _width;
}

float GameObject::getHeight()
{
	return _height;
}

float GameObject::getNextX() {
	return _nextX;
}

float GameObject::getNextY() {
	return _nextY;
}

void GameObject::setX(float x) {
	_x = x;
}

void GameObject::setY(float y) {
	_y = y;
}

bool GameObject::isDead() {
	return _dead;
}

void GameObject::update(Game& game) {

}

void GameObject::draw(Game& game) {

}

void GameObject::getHit() {

}

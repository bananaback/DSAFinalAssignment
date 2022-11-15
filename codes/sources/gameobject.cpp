#include "../headers/gameobject.h"

GameObject::GameObject(float x, float y, float width, float height) {
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_isDestroyed = false;
}

GameObject::~GameObject() {

}

float GameObject::getX() {
	return _x;
}

float GameObject::getY() {
	return _y;
}

float GameObject::getWidth() {
	return _width;
}

float GameObject::getHeight() {
	return _height;
}

bool GameObject::isDestroyed() {
	return _isDestroyed;
}

void GameObject::setDestroy(bool b) {
	_isDestroyed = b;
}
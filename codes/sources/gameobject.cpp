#include "../headers/gameobject.h"
#include "../headers/calculator.h"
#include <memory>
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

void GameObject::destroy() {
	_isDestroyed = true;
}

bool GameObject::checkCollision(GameObject& other) {
	float l1 = this->_x;
	float t1 = this->_y;
	float r1 = this->_x + this->_width;
	float b1 = this->_y + this->_height;
	float l2 = other._x;
	float t2 = other._y;
	float r2 = other._x + other._width;
	float b2 = other._y + other._height;

	if (l1 > r2 || l2 > r1) return false;
	if (t1 > b2 || t2 > b1) return false;
	return true;
}

int GameObject::getCollisionStatus(GameObject& other, int offset) {
    int collisionFlag = 0;
    int otherX = other.getX(), otherY = other.getY();
    int otherW = other.getWidth(), otherH = other.getHeight();

    if (checkCollisionBetweenTwoRect(
        _x, _y - offset, _width, _height + offset,
        otherX, otherY, otherW, otherH)) {
        collisionFlag |= COLLISION_UP;
    }

    if (checkCollisionBetweenTwoRect(
        _x, _y, _width, _height + offset,
        otherX, otherY, otherW, otherH)) {
        collisionFlag |= COLLISION_DOWN;
    }

    if (checkCollisionBetweenTwoRect(
        _x - offset, _y, _width + offset, _height,
        otherX, otherY, otherW, otherH)) {
        collisionFlag |= COLLISION_LEFT;
    }

    if (checkCollisionBetweenTwoRect(
        _x, _y, _width + offset, _height,
        otherX, otherY, otherW, otherH)) {
        collisionFlag |= COLLISION_RIGHT;
    }

    return collisionFlag;
}
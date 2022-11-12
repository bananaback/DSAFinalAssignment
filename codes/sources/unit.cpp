#include "../headers/unit.h"

Unit::Unit(float x, float y) {
	_x = x;
	_y = y;
	_prev = nullptr;
	_next = nullptr;
	_dead = false;
}

float Unit::getX() {
	return _x;
}

float Unit::getY() {
	return _y;
}

float Unit::getNextX() {
	return _nextX;
}

float Unit::getNextY() {
	return _nextY;
}

void Unit::setX(float x) {
	_x = x;
}

void Unit::setY(float y) {
	_y = y;
}

void Unit::update(Game& game){

}

void Unit::draw(Game& game){

}

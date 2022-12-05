#include <iostream>
#include "../headers/effect.h"
#include "../headers/gameobject.h"

Effect::Effect(float x, float y, float width, float height, Game& game) : GameObject(x, y, width, height) {
	_scale = 1;
}

Effect::~Effect() {
	
}

void Effect::update(Game& game) {
	_holdingAnimation->update(game._dt);
	if (_holdingAnimation->_finishOnce) _isDestroyed = true;
}

void Effect::draw(Game& game) {
	_holdingAnimation->draw(game, _x + _width / 2, _y + _height / 2, 0, _scale*1, _scale*1, _holdingAnimation->_w / 2, _holdingAnimation->_h / 2);
}
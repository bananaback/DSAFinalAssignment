#include <iostream>
#include "../headers/effect.h"
#include "../headers/gameobject.h"

Effect::Effect(float x, float y, float width, float height, Game& game) : GameObject(x, y, width, height) {
	std::cout << "I'm effect\n";
	//_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::EXPLOSION2], 0, 0, 12, 12, 3, 0.1, "explosion2");
	//_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::EXPLOSION1], 0, 0, 50, 50, 3, 0.1, "explosion1");

}

Effect::~Effect() {
	std::cout << "Effect destroyed\n";
}

void Effect::update(Game& game) {
	_holdingAnimation->update(game._dt);
	if (_holdingAnimation->_finishOnce) _isDestroyed = true;
}

void Effect::draw(Game& game) {
	_holdingAnimation->draw(game, _x + _width / 2, _y + _height / 2, 0, 1, 1, _holdingAnimation->_w / 2, _holdingAnimation->_h / 2);
}
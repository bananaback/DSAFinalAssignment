#include "../headers/cannondisplay.h"

CannonDisplay::CannonDisplay(Game& game, float x, float y, float scale) : WeaponDisplay(game) {
	_x = x;
	_y = y;
	_scale = scale;
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_UP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DIAGUP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_SIDE]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DIAGDOWN]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNON_DOWN]);

	for (int i = 0; i < 5; i++) {
		_textureSize.push_back(std::make_pair(_textureSet[i]->getSize().x, _textureSet[i]->getSize().y));
	}
}

CannonDisplay::~CannonDisplay() {

}

void CannonDisplay::update(Game& game) {

}
#include <iostream>
#include "../headers/resource_allocator.h"
#include "../headers/cannon.h"

Cannon::Cannon(Game& game, float x, float y, float scale) : Weapon(game) {
	_x = x;
	_y = y;
	_scale = scale;
	_sprite.setScale(sf::Vector2f(_scale, _scale));
	//---------------------------------ADJUST HERE-------------------------------------------
	_textureSet.push_back(game.ra_ptr->_imageResources[IMAGE::CANNON_UP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[IMAGE::CANNON_DIAGUP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[IMAGE::CANNON_SIDE]);
	_textureSet.push_back(game.ra_ptr->_imageResources[IMAGE::CANNON_DIAGDOWN]);
	_textureSet.push_back(game.ra_ptr->_imageResources[IMAGE::CANNON_DOWN]);
	_radius = 20;
	//---------------------------------------------------------------------------------------
	for (int i = 0; i <= 8; i++) {
		_textureSize.push_back(std::make_pair(_textureSet[dirMap[i]]->getSize().x, 
			_textureSet[dirMap[i]]->getSize().y));
	}
}

Cannon::~Cannon() {

}

void Cannon::update(Game& game, float angle, float playerCenterX, float playerCenterY) {
	Weapon::updateWeapon(game, angle, playerCenterX, playerCenterY);
}

void Cannon::draw(Game& game) {
	Weapon::drawWeapon(game);	
}
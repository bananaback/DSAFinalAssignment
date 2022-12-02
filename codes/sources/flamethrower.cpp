#include "../headers/flamethrower.h"

FlameThrower::FlameThrower(Game& game, float x, float y, float scale) : Weapon(game) {
	_x = x;
	_y = y;
	_scale = scale;
	_sprite.setScale(sf::Vector2f(_scale, _scale));
	//---------------------------------ADJUST HERE-------------------------------------------
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::FLAMETHROWER_UP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::FLAMETHROWER_DIAGUP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::FLAMETHROWER_SIDE]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::FLAMETHROWER_DIAGDOWN]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::FLAMETHROWER_DOWN]);
	_radius = 30;
	//---------------------------------------------------------------------------------------
	for (int i = 0; i <= 8; i++) {
		_textureSize.push_back(std::make_pair(_textureSet[dirMap[i]]->getSize().x,
			_textureSet[dirMap[i]]->getSize().y));
	}
}

FlameThrower::~FlameThrower() {

}

void FlameThrower::update(Game& game, float angle, float playerCenterX, float playerCenterY) {
	Weapon::updateWeapon(game, angle, playerCenterX, playerCenterY);
}

void FlameThrower::draw(Game& game) {
	Weapon::drawWeapon(game);
}
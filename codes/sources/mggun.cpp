#include "../headers/mggun.h"

MgGun::MgGun(Game& game, float x, float y, float scale) : Weapon(game) {
	_x = x;
	_y = y;
	_scale = scale;
	_sprite.setScale(sf::Vector2f(_scale, _scale));
	//---------------------------------ADJUST HERE-------------------------------------------
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MG_UP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MG_DIAGUP]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MG_SIDE]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MG_DIAGDOWN]);
	_textureSet.push_back(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MG_DOWN]);
	_radius = 30;
	//---------------------------------------------------------------------------------------
	for (int i = 0; i <= 8; i++) {
		_textureSize.push_back(std::make_pair(_textureSet[dirMap[i]]->getSize().x,
			_textureSet[dirMap[i]]->getSize().y));
	}
}

MgGun::~MgGun() {

}

void MgGun::update(Game& game, float angle, float playerCenterX, float playerCenterY) {
	Weapon::updateWeapon(game, angle, playerCenterX, playerCenterY);
}

void MgGun::draw(Game& game) {
	Weapon::drawWeapon(game);
}
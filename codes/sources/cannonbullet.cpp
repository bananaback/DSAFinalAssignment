#include "../headers/cannonbullet.h"

CannonBullet::CannonBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 300;
	_damageDeal = 20;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNONBALL], 0, 0, 17, 17, 1, 1, "cannonball");
	_durability = 1;
	_durabilityReduceAmount = 1;
}

CannonBullet::~CannonBullet() {

}

void CannonBullet::update(Game& game) {
	_x = _x + std::cos(_angle) * _speed * game._dt;
	_y = _y + std::sin(_angle) * _speed * game._dt;
	_timer += game._dt;
	if (_timer >= 1) {
		_isDestroyed = true;
		_timer = 0;
	}
	if (_durability <= 0) {
		_isDestroyed = true;
	}
}

void CannonBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, 0, 2, 2, 17.f / 2, 17.f / 2);
	
}

void CannonBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {

}
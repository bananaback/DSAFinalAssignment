#include "../headers/mgbullet.h"
#include "../headers/explosioneffect2.h"

MgBullet::MgBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 500;
	_damageDeal = 10;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MG_BULLET], 0, 0, 11, 8, 1, 1, "mg");
	_durability = 2;
	_durabilityReduceAmount = 1;
}

MgBullet::~MgBullet() {

}

void MgBullet::update(Game& game) {
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
	_animation->update(game._dt);
}

void MgBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _angle * 180.f / (std::atan(1) * 4), 2, 2, 13.f / 2, 10.f / 2);

}

void MgBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<ExplosionEffect2>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
#include "../headers/catbullet.h"
#include "../headers/catscratch.h"

CatBullet::CatBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 250;
	_damageDeal = 15;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CAT], 0, 0, 19, 14, 1, 1, "cat");
	_durability = 2;
	_durabilityReduceAmount = 1;
	_displayAngle = angle;

	if (std::abs(_angle * 180.f / (std::atan(1) * 4)) <= 90) {
		_scaleY = 1;
		_spinDir = 1;
	} else {
		_scaleY = -1;
		_spinDir = -1;
	}
}

CatBullet::~CatBullet() {

}

void CatBullet::update(Game& game) {
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
	_displayAngle += 1 * game._dt * _spinDir;
}

void CatBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _displayAngle * 180.f / (std::atan(1) * 4), 2, 2*_scaleY, 19.f / 2, 14.f / 2);

}

void CatBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<CatScratch>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
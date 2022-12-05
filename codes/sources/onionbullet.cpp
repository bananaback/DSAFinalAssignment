#include "../headers/onionbullet.h"
#include "../headers/onioneffect.h"

OnionBullet::OnionBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 300;
	_damageDeal = 15;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::ONION], 0, 0, 13, 13, 1, 1, "onion");
	_durability = 2;
	_durabilityReduceAmount = 1;
	_displayAngle = angle;
	
}

OnionBullet::~OnionBullet() {

}

void OnionBullet::update(Game& game) {
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
	_displayAngle += 2 * game._dt;
}

void OnionBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _displayAngle * 180.f / (std::atan(1) * 4), 2, 2, 13.f / 2, 13.f / 2);

}

void OnionBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<OnionEffect>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
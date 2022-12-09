#include "../headers/resource_allocator.h"
#include "../headers/onion_bullet.h"
#include "../headers/onioneffect.h"
#include "../headers/calculator.h"

OnionBullet::OnionBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 300;
	_damageDeal = 15;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::ONION], 0, 0, getFrameWidth(), getFrameHeight(), 1, 1, "onion");
	_durability = 2;
	_durabilityReduceAmount = 1;
	_displayAngle = rad2deg(angle);

	spinBulletInitialize(_scaleY, _spinDir);
}

OnionBullet::~OnionBullet() {

}

void OnionBullet::update(Game& game) {
	PlayerBullet::movingWithAngle(game);
	PlayerBullet::checkRemove(game, 1);
	PlayerBullet::updateAnimForSpinBullet(game, _displayAngle, _spinDir);
}

void OnionBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _displayAngle, 2, 2, getFrameWidth() / 2.f, getFrameHeight() / 2.f);

}

void OnionBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<OnionEffect>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
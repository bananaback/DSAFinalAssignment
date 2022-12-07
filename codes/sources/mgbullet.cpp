#include "../headers/mgbullet.h"
#include "../headers/explosioneffect2.h"
#include "../headers/calculator.h"

MgBullet::MgBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 500;
	_damageDeal = 10;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MG_BULLET], 0, 0, getFrameWidth(), getFrameHeight(), 1, 1, "mg");
	_durability = 2;
	_durabilityReduceAmount = 1;
	_displayAngle = rad2deg(_angle);
}

MgBullet::~MgBullet() {

}

void MgBullet::update(Game& game) {
	PlayerBullet::movingWithAngle(game);
	PlayerBullet::checkRemove(game, 3);
	_animation->update(game._dt);
}

void MgBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _displayAngle, 2, 2, 1.f * getFrameWidth() / 2, 1.f * getFrameHeight() / 2);

}

void MgBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<ExplosionEffect2>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
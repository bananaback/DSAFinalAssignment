#include "../headers/cannon_bullet.h"

CannonBullet::CannonBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 300;
	_damageDeal = 20;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CANNONBALL], 0, 0, getFrameWidth(), getFrameHeight(), 1, 1, "cannonball");
	_durability = 1;
	_durabilityReduceAmount = 1;
}

CannonBullet::~CannonBullet() {

}

void CannonBullet::update(Game& game) {
	PlayerBullet::movingWithAngle(game);
	PlayerBullet::checkRemove(game, 1);
}

void CannonBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, 0, 2, 2, 1.f * getFrameWidth() / 2, 1.f * getFrameHeight() / 2);
	
}

void CannonBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {

}
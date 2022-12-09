#include "../headers/tomato_bullet.h"
#include "../headers/tomatoeffect.h"
#include "../headers/calculator.h"

TomatoBullet::TomatoBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 300;
	_damageDeal = 15;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::TOMATO], 0, 0, getFrameWidth(), getFrameHeight(), 1, 1, "tomato");
	_durability = 2;
	_durabilityReduceAmount = 1;
	_displayAngle = rad2deg(angle);
	spinBulletInitialize(_scaleY, _spinDir);
}

TomatoBullet::~TomatoBullet() {

}

void TomatoBullet::update(Game& game) {
	PlayerBullet::movingWithAngle(game);
	PlayerBullet::checkRemove(game, 1);
	PlayerBullet::updateAnimForSpinBullet(game, _displayAngle, _spinDir);
}

void TomatoBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _displayAngle, 2, 2, 1.f * getFrameWidth() / 2, 1.f * getFrameHeight() / 2);

}

void TomatoBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<TomatoEffect>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
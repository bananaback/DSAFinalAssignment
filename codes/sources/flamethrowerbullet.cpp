#include <iostream>
#include "../headers/flamethrowerbullet.h"
#include "../headers/explosioneffect2.h"
#include "../headers/explosioneffect1.h"
#include "../headers/flameeffect.h"
#include "../headers/calculator.h"
FlameThrowerBullet::FlameThrowerBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 200;
	_damageDeal = 1;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::FLAMETHROWER_BULLET], 0, 0, getFrameWidth(), getFrameHeight(), 2, 0.1, "flame");
	_durability = 10;
	_durabilityReduceAmount = 1;
	_displayAngle = rad2deg(angle);
}

FlameThrowerBullet::~FlameThrowerBullet() {
	
}

void FlameThrowerBullet::update(Game& game) {
	PlayerBullet::movingWithAngle(game);
	PlayerBullet::checkRemove(game, 1);
	_animation->update(game._dt);
}

void FlameThrowerBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _displayAngle, 2, 2, 1.f * getFrameWidth() / 2, 1.f * getFrameHeight() / 2);
}

void FlameThrowerBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<FlameEffect>(_x + _width/2, _y + _height/2, 0, 0, game));
}
#include "../headers/resource_allocator.h"
#include "../headers/cat_bullet.h"
#include "../headers/catscratch.h"
#include "../headers/calculator.h"

CatBullet::CatBullet(Game& game, float x, float y, float width, float height, float angle) : PlayerBullet(game, x, y, width, height, angle) {
	_speed = 250;
	_damageDeal = 15;
	_angle = angle;
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::CAT], 0, 0, getFrameWidth(), getFrameHeight(), 1, 1, "cat");
	_durability = 2;
	_durabilityReduceAmount = 1;
	_displayAngle = rad2deg(angle);

	spinBulletInitialize(_scaleY, _spinDir);
}

CatBullet::~CatBullet() {

}

void CatBullet::update(Game& game) {
	PlayerBullet::movingWithAngle(game);
	PlayerBullet::checkRemove(game, 1);
	PlayerBullet::updateAnimForSpinBullet(game, _displayAngle, _spinDir);
}

void CatBullet::draw(Game& game) {
	_animation->draw(game, _x + _width / 2, _y + _height / 2, _displayAngle, 2, 2*_scaleY, getFrameWidth() / 2.f, getFrameHeight() / 2.f);

}

void CatBullet::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<CatScratch>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
#include "../headers/player_bullet.h"

PlayerBullet::PlayerBullet(Game& game, float x, float y, float width, float height, float angle) : GameObject(x, y, width, height) {
	_timer = 0;
	_angle = 0;
	_speed = 0;
	_damageDeal = 0;
	_timer = 0;
	_durability = 0;
	_durabilityReduceAmount = 0;
}

PlayerBullet::~PlayerBullet() {

}

void PlayerBullet::spinBulletInitialize(float& scaleY, float& spinDir) {
	if (std::abs(_angle) <= std::acos(0)) {
		scaleY = 1;
		spinDir = 1;
	}
	else {
		scaleY = -1;
		spinDir = -1;
	}
}

void PlayerBullet::updateAnimForSpinBullet(Game& game, float& displayAngle, float& spinDir) {
	_animation->update(game._dt);
	displayAngle += 100 * game._dt * spinDir;
}

void PlayerBullet::movingWithAngle(Game& game) {
	_x = _x + std::cos(_angle) * _speed * game._dt;
	_y = _y + std::sin(_angle) * _speed * game._dt;
}

void PlayerBullet::checkRemove(Game& game, float t) {
	_timer += game._dt;
	if (_timer >= t) {
		_isDestroyed = true;
		_timer = 0;
	}
	if (_durability <= 0) {
		_isDestroyed = true;
	}
}

void PlayerBullet::reduceDurability(int d) {
	if (_durability > 0)_durability -= d;
}

int PlayerBullet::getDurabilityReduceAmount() {
	return _durabilityReduceAmount;
}

int PlayerBullet::getDurability() {
	return _durability;
}

float PlayerBullet::getDamage() {
	return _damageDeal;
}
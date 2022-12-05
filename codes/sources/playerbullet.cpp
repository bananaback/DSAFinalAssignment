#include "../headers/playerbullet.h"

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
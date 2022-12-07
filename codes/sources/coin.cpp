#include "../headers/coin.h"
#include "../headers/collectableitem.h"
#include "../headers/calculator.h"

Coin::Coin(float x, float y, float width, float height, Game& game) : CollectableItem(x, y, width, height, game) {
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::COIN_BIG], 0, 0, 16, 16, 8, 0.1, "coin");
	_scaleX = 2;
	_scaleY = 2;
	_value = 10;
	_timer = 0;
	_flickerTimer = 0;
	_flickInterval = 0;
	_display = true;
}

Coin::~Coin() {

}

void Coin::update(Game& game, float playerCenterX, float playerCenterY) {
	CollectableItem::updateAnim(game);
	float d = distance(_x, _y, playerCenterX, playerCenterY);
	if (d < 100) {
		float angle = calculateAngle(_x, _y, playerCenterX, playerCenterY);
		_x += std::cos(angle) * game._dt * 200;
		_y += std::sin(angle) * game._dt * 200;
	}
	_timer += game._dt;
	if (_timer >= 10) {
		_flickerTimer += game._dt;
		if (_flickerTimer >= 5) {
			_isDestroyed = true;
		}
	}
	if (_flickerTimer > 0) {
		_flickInterval += game._dt;
		if (_flickInterval >= 0.1) {
			_flickInterval = 0;
			_display = !_display;
		}
	}
}

void Coin::draw(Game& game) {
	if (_display) {
		CollectableItem::drawAnim(game);
	}
}

void Coin::activate(Player& player) {
	player.increaseCoin(_value);
}
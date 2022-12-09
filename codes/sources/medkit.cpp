#include "../headers/medkit.h"
#include "../headers/calculator.h"
Medkit::Medkit(float x, float y, float width, float height, Game& game) : CollectableItem(x, y, width, height, game) {
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MEDKIT], 0, 0, 16, 16, 4, 0.1, "medkit");
	_scaleX = 2;
	_scaleY = 2;
	_regenValue = 20;
}

Medkit::~Medkit() {

}

void Medkit::update(Game& game, float playerCenterX, float playerCenterY) {
	CollectableItem::updateAnim(game);
	float d = distance(_x, _y, playerCenterX, playerCenterY);
	if (d < 100) {
		float angle = calculateAngle(_x, _y, playerCenterX, playerCenterY);
		_x += std::cos(angle) * game._dt * 200;
		_y += std::sin(angle) * game._dt * 200;
	}
}

void Medkit::draw(Game& game) {
	CollectableItem::drawAnim(game);
}

void Medkit::activate(Player& player) {
	player.increaseHealth(_regenValue);
}
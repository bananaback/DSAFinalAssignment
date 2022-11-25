#include "../headers/medkit.h"
Medkit::Medkit(float x, float y, float width, float height, Game& game) : CollectableItem(x, y, width, height, game) {
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MEDKIT], 0, 0, 16, 16, 4, 0.1, "medkit");
	_scaleX = 2;
	_scaleY = 2;
	_regenValue = 20;
}

Medkit::~Medkit() {

}

void Medkit::update(Game& game) {
	CollectableItem::update(game);
}

void Medkit::draw(Game& game) {
	CollectableItem::draw(game);
}

void Medkit::activate(Player& player) {
	player.increaseHealth(_regenValue);
}
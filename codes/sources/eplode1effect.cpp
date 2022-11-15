#include "../headers/explode1effect.h"

Explode1Effect::Explode1Effect(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::EXPLOSION1], 0, 0, 12, 12, 3, 0.1, "explosion1");
}

Explode1Effect::~Explode1Effect() {

}

void Explode1Effect::update(Game& game) {
	Effect::update(game);
}

void Explode1Effect::draw(Game& game) {
	Effect::draw(game);
}


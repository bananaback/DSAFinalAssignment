#include "../headers/resource_allocator.h"
#include "../headers/flameeffect.h"

FlameEffect::FlameEffect(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::BURNING], 0, 0, 16, 13, 4, 0.1, "burning");
	_scale = 3;
}

FlameEffect::~FlameEffect() {

}

void FlameEffect::update(Game& game) {
	Effect::update(game);
}

void FlameEffect::draw(Game& game) {
	Effect::draw(game);
}
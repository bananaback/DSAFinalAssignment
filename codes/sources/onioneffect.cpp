#include "../headers/resource_allocator.h"
#include "../headers/onioneffect.h"

OnionEffect::OnionEffect(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::ONION_EFFECT], 0, 0, 28, 29, 5, 0.05, "onioneffect");
	_scale = 2;
}

OnionEffect::~OnionEffect() {

}

void OnionEffect::update(Game& game) {
	Effect::update(game);
}

void OnionEffect::draw(Game& game) {
	Effect::draw(game);
}
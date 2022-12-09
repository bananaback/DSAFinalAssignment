#include "../headers/dust.h"
#include "../headers/resource_allocator.h"

Dust::Dust(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[IMAGE::DUST], 0, 0, 16, 16, 5, 0.1, "dust");
	_scale = 2;
}

Dust::~Dust() {

}

void Dust::update(Game& game) {
	Effect::update(game);
}

void Dust::draw(Game& game) {
	Effect::draw(game);
}
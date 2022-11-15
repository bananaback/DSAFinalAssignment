#include "../headers/explosioneffect2.h"

ExplosionEffect2::ExplosionEffect2(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::EXPLOSION_BIG], 0, 0, 50, 50, 3, 0.1, "explosion1");
}

ExplosionEffect2::~ExplosionEffect2() {

}

void ExplosionEffect2::update(Game& game) {
	Effect::update(game);
}

void ExplosionEffect2::draw(Game& game) {
	Effect::draw(game);
}
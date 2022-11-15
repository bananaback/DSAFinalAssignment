#include "../headers/explosioneffect1.h"

ExplosionEffect1::ExplosionEffect1(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::EXPLOSION_SMALL], 0, 0, 12, 12, 3, 0.1, "explosion1");
}

ExplosionEffect1::~ExplosionEffect1() {

}

void ExplosionEffect1::update(Game& game) {
	Effect::update(game);
}

void ExplosionEffect1::draw(Game& game) {
	Effect::draw(game);
}


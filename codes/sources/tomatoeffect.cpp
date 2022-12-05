#include "../headers/tomatoeffect.h"

TomatoEffect::TomatoEffect(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::TOMATO_EFFECT], 0, 0, 22, 22, 5, 0.05, "onioneffect");
	_scale = 2;
}

TomatoEffect::~TomatoEffect() {

}

void TomatoEffect::update(Game& game) {
	Effect::update(game);
}

void TomatoEffect::draw(Game& game) {
	Effect::draw(game);
}
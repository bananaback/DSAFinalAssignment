#include "../headers/catscratch.h"

CatScratch::CatScratch(float x, float y, float width, float height, Game& game) : Effect(x, y, width, height, game) {
	_holdingAnimation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CAT_SCRATCH], 0, 0, 18, 18, 5, 0.1, "catscratch");
	_scale = 2;
}

CatScratch::~CatScratch() {

}

void CatScratch::update(Game& game) {
	Effect::update(game);
}

void CatScratch::draw(Game& game) {
	Effect::draw(game);
}
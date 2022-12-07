#include "../headers/collectableitem.h"
#include "../headers/dust.h"

CollectableItem::CollectableItem(float x, float y, float width, float height, Game& game):GameObject(x,y,width,height) {
//	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::COIN_BIG], 0, 0, 16, 16, 8, 0.1, "coin");
	_scaleX = 2;
	_scaleY = 2;
}
CollectableItem::~CollectableItem() {

}

void CollectableItem::updateAnim(Game& game) {
	_animation->update(game._dt);
}
void CollectableItem::drawAnim(Game& game) {
	_animation->draw(game,_x + _width/2,_y+_height/2,0,_scaleX, _scaleY,8,8);
}

void CollectableItem::addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) {
	effectList.push_back(std::make_shared<Dust>(_x + _width / 2, _y + _height / 2, 0, 0, game));
}
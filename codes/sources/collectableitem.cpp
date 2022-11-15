#include "../headers/collectableitem.h"

CollectableItem::CollectableItem(float x, float y, float width, float height, Game& game):GameObject(x,y,width,height) {
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::COIN_BIG], 0, 0, 16, 16, 8, 0.1, "coin");
}
CollectableItem::~CollectableItem() {

}
void CollectableItem::update(Game& game) {
	_animation->update(game._dt);
}
void CollectableItem::draw(Game& game) {
	_animation->draw(game,_x + _width/2,_y+_height/2,0,1,1,8,8);
}
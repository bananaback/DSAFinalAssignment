#include "../headers/coin.h"
#include "../headers/collectableitem.h"

Coin::Coin(float x, float y, float width, float height, Game& game) : CollectableItem(x, y, width, height, game) {
	_animation = std::make_shared<Animation>(game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::COIN_BIG], 0, 0, 16, 16, 8, 0.1, "coin");
	_scaleX = 2;
	_scaleY = 2;
	_value = 10;
}

Coin::~Coin() {

}

void Coin::update(Game& game) {
	CollectableItem::update(game);
}

void Coin::draw(Game& game) {
	CollectableItem::draw(game);
}

void Coin::activate(Player& player) {
	player.increaseCoin(_value);
}
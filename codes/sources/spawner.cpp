#include "../headers/spawner.h"

Spawner::Spawner(Game& game, float x, float y, std::vector<std::pair<int, std::string>> spawnScript) : GameObject(x, y, 48, 48) {
	_sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
	_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::BASE]);
	_sprite.setPosition(x, y);
	_sprite.setColor(sf::Color(255, 255, 255, 255));
}

Spawner::~Spawner() {

}

void Spawner::update(Game& game) {

}

void Spawner::draw(Game& game) {
	game._window.draw(_sprite);
}
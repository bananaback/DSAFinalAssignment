#include "../headers/resource_allocator.h"
#include "../headers/wall.h"
#include "../headers/gameobject.h"

Wall::Wall(float x, float y, float width, float height, Game& game, int id) : GameObject(x, y, width, height) {
	_sprite.setTexture(*game.ra_ptr->_imageResources[IMAGE::TILES]);
	_sprite.setTextureRect(game.ra_ptr->_tilesImgRects[id]);
	_sprite.setOrigin(sf::Vector2f(8.f, 8.f));
	_sprite.setPosition(sf::Vector2f(_x + _width / 2, _y + _height / 2));
	_sprite.setScale(sf::Vector2f(3.f, 3.f));
}

Wall::~Wall() {

}

int Wall::getId() {
	return _id;
}

void Wall::update(Game& game) {

}

void Wall::draw(Game& game) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);
	game._window.draw(_sprite);

}
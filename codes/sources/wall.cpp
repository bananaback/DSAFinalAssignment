#include "../headers/wall.h"
#include "../headers/gameobject.h"
Wall::Wall(float x, float y, float width, float height, Game& game, int id) : GameObject(x, y, width, height) {
	if (id == 1) {
		_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::BOXWALL]);
	}
	else if (id == 2) {
		_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::GREENWALL]);
	}
	else if (id == 3) {
		_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::REDWALL]);
	}
	else if (id == 4) {
		_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::BLUEWALL]);
	}
	else if (id == 5) {
		_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::ICEWALL]);
	}

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
	//rectangle.setOutlineColor(sf::Color::Blue);
	//rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	//game._window.draw(rectangle);
	game._window.draw(_sprite);

}
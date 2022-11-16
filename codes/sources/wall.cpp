#include "../headers/wall.h"
#include "../headers/gameobject.h"
Wall::Wall(float x, float y, float width, float height, Game& game) : GameObject(x, y, width, height) {

}

Wall::~Wall() {

}

void Wall::update(Game& game) {

}

void Wall::draw(Game& game) {
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(_x, _y);
	game._window.draw(rectangle);
}
#include "../headers/spawner.h"
#include "../headers/effect.h"
#include "../headers/dust.h"

Spawner::Spawner(Game& game, float x, float y, std::vector<std::pair<int, std::string>> spawnScript) : GameObject(x, y, 48, 48) {
	_sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
	_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::BASE]);
	_sprite.setPosition(x, y);
	_sprite.setColor(sf::Color(255, 255, 255, 255));

	_healthPoint = 100;
}

Spawner::~Spawner() {

}

float Spawner::getHealthPoint() {
	return _healthPoint;
}

void Spawner::setHealthPoint(float f) {
	_healthPoint = f;
}

void Spawner::takeDamage(float d) {
	_healthPoint -= d;
}

void Spawner::update(Game& game) {
	if (_healthPoint <= 0) _isDestroyed = true;
}

void Spawner::drawHealthBar(Game& game) {
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(_healthPoint, 10));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(_x - 26, _y - 20);
	game._window.draw(rect);
}

void Spawner::draw(Game& game) {
	game._window.draw(_sprite);
	drawHealthBar(game);
}
#include "../headers/spawner.h"
#include "../headers/effect.h"
#include "../headers/dust.h"

Spawner::Spawner(Game& game, float x, float y, std::vector<std::pair<int, std::string>> spawnScript) : GameObject(x, y, 48, 48) {
	_sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
	_sprite.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::BASE]);
	_sprite.setPosition(x+24, y+24);
	_sprite.setColor(sf::Color(255, 255, 255, 255));
	_sprite.setOrigin(24, 24);

	_healthPoint = 1000;
	_spawnScript = spawnScript;

	_spawnScale = 1;
	_spawnMinScale = 1;

	_healthBarOpacity = 255;
}

Spawner::~Spawner() {

}

void Spawner::setScale(float s) {
	_spawnScale = s;
}

size_t Spawner::getQueueLength() {
	return _spawnScript.size();
}

std::uniform_int_distribution<> enemyNumberDistr(5, 10); // define the range
std::uniform_int_distribution<> spawnIntervalDistr(3, 6);
// random enemy type soon...

void Spawner::generateSpawnQueue(Game& game, float timer) {
	int enemyNumber = enemyNumberDistr(game.gen);
	float startTime = timer;
	for (int i = 0; i < enemyNumber; i++) {
		std::pair<float, std::string> element;
		int interval = spawnIntervalDistr(game.gen);
		element.first = startTime + interval;
		element.second = "slime";
		startTime += interval;
		_spawnScript.push_back(element);
	}
}

std::pair<bool, std::string> Spawner::checkSpawn(float timer) {
	std::pair<bool, std::string> res = std::make_pair(false, "");
	for (size_t i = 0; i < _spawnScript.size(); i++) {
		if (timer >= _spawnScript[i].first) {
			res.first = true;
			res.second = _spawnScript[i].second;
			_spawnScript.erase(_spawnScript.begin()+i);
			break;
		}
	}
	return res;
}

float Spawner::getHealthPoint() {
	return _healthPoint;
}

void Spawner::setHealthPoint(float f) {
	_healthPoint = f;
}

void Spawner::takeDamage(float d) {
	_healthPoint -= d;
	_healthBarOpacity = 255;
}

void Spawner::update(Game& game) {
	if (_healthPoint <= 0) _isDestroyed = true;
	if (_spawnScale > _spawnMinScale) {
		_spawnScale -= game._dt * 5;
	} else {
		_spawnScale = _spawnMinScale;
	}
	if (_healthBarOpacity > 0) {
		_healthBarOpacity -= game._dt * 255;
	} else {
		_healthBarOpacity = 0;
	}
}

void Spawner::drawHealthBar(Game& game) {
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(_healthPoint/10, 8));
	rect.setFillColor(sf::Color(255, 0, 0, _healthBarOpacity));
	rect.setPosition(_x - 26, _y - 20);
	game._window.draw(rect);
}

void Spawner::draw(Game& game) {
	_sprite.setScale(_spawnScale, _spawnScale);
	game._window.draw(_sprite);
	drawHealthBar(game);
}
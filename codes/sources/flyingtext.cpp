#include "../headers/resource_allocator.h"
#include "../headers/flyingtext.h"

FlyingText::FlyingText(float x, float y, float size, float limitX, std::string color, std::string context, Game& game) {
	_x = x;
	_y = y;
	_limitX = limitX;
	_context.setFont(*game.ra_ptr->_fontResources[FONT::THALEAHFAT]);
	_context.setCharacterSize(size);
	_context.setString(context);
	_context.setPosition(sf::Vector2f(_x, _y));
	if (color == "black") {
		_context.setFillColor(sf::Color::Black);
	}
	_timer = 0;
	_lifeTime = 3;
	_opacity = 255;
	_isDestroyed = false;
}

FlyingText::~FlyingText() {

}

bool FlyingText::isDestroyed() {
	return _isDestroyed;
}

void FlyingText::update(Game& game) {
	_timer += _timer + game._dt;
	if (_timer >= _lifeTime) {
		_opacity -= game._dt * 200;
		if (_opacity <= 0) {
			_isDestroyed = true;
		}
	}
	if (_x < _limitX) _x += 1000 * game._dt;
	_context.setPosition(sf::Vector2f(_x, _y));
}

void FlyingText::draw(Game& game) {
	_context.setFillColor(sf::Color(0, 0, 0, _opacity));
	game._window.draw(_context);
}
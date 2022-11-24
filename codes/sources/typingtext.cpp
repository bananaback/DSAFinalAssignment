#include <iostream>
#include "../headers/typingtext.h"

TypingText::TypingText(float x, float y, float size, float speed, std::string context, Game& game) {
	_x = x;
	_y = y;
	_size = size;
	_speed = speed;
	_context = context;
	_currentContext = "";
	_currentText.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_currentText.setString(_currentContext);
	_currentText.setCharacterSize(_size);
	_currentText.setFillColor(sf::Color::Black);
	_currentText.setPosition(_x, _y);
	_timer = 0;
}

TypingText::~TypingText() {

}

void TypingText::update(Game& game) {
	_timer += game._dt;
	if (_timer >= _speed) {
		if (_currentContext.length() < _context.length()) {
			_currentContext += _context[_currentContext.length()];
			_currentText.setString(_currentContext);
		}
		_timer = 0;
	}
}

void TypingText::draw(Game& game) {
	game._window.draw(_currentText);
}
#pragma once
#ifndef TYPINGTEXT_H
#define TYPINGTEXT_H

#include <cstring>
#include "game.h"

class TypingText {
public:
	TypingText(float x, float y, float size, float speed, std::string context, Game& game);
	~TypingText();
	void update(Game& game);
	void draw(Game& game);
private:
	float _x, _y, _size, _speed, _timer;
	std::string _context, _currentContext;
	sf::Text _currentText;
};

#endif // !TYPINGTEXT_H

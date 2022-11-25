#pragma once
#ifndef FLYINGTEXT_H
#define FLYINGTEXT_H

#include <cstring>
#include "SFML/Graphics.hpp"
#include "game.h"

class FlyingText {
public:
	FlyingText(float x, float y, float size, float limitX, std::string color, std::string context, Game& game);
	~FlyingText();
	void update(Game& game);
	void draw(Game& game);
	bool isDestroyed();
private:
	float _x, _y, _limitX, _lifeTime, _timer, _opacity;
	bool _isDestroyed;
	sf::Text _context;
};

#endif // !FLYINGTEXT_H

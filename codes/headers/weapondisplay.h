#pragma once
#ifndef WEAPONDISPLAY_H
#define WEAPONDISPLAY_H

#include "game.h"


class WeaponDisplay {
public:
	WeaponDisplay(Game& game);
	~WeaponDisplay();
	virtual void update(Game& game) = 0;
	virtual void draw(Game& game) = 0;
protected:
	// north northeast east southeast south southwest west northwest
	// 0     1         2    3         4     3         2    1
	sf::Sprite _sprite;
	std::vector<std::shared_ptr<sf::Texture>> _textureSet;
	std::vector<std::pair<int, int>> _textureSize;
	float _x, _y, _width, _height, _scale, _centerX, _centerY;
};

#endif
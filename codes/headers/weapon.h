#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include "game.h"


class Weapon {
public:
	Weapon(Game& game);
	~Weapon();
	virtual void update(Game& game, float angle, float playerCenterX, float playerCenterY) = 0;
	virtual void draw(Game& game) = 0;
	int determineDirFromAngle(float angle);
	void updateWeapon(Game& game, float angle, float playerCenterX, float playerCenterY);
	void drawWeapon(Game& game);
protected:
	// north northeast east southeast south southwest west northwest
	// 6     7         08   1         2     3         4    5
	// 0     1         2    3         4     3         2    1

	std::vector<int> dirMap, scaleXMap, angleMap;
	sf::Sprite _sprite;
	std::vector<std::shared_ptr<sf::Texture>> _textureSet;
	std::vector<std::pair<int, int>> _textureSize;
	int _currentDir;
	float _x, _y, _width, _height, _scale, _centerX, _centerY, _radius;
};

#endif
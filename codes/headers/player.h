#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "animation.h"
#include "unit.h"

class Player : public Unit{
public:
	Player(float x, float y, float width, float height, Game &game);
	~Player();
	void update(Game& game);
	void draw(Game& game);
private:
	float _width, _height;
	std::string _name;
	std::vector<std::shared_ptr<Animation>> _animations;
	int _currentAnimation, _scaleX, _scaleY;
	int _assetName[9] = { 0, 2, 4, 2, 0, 1, 3, 1, 0 };
	sf::Text _playerDebugMessage;
	sf::Font _monoFont;
};

#endif
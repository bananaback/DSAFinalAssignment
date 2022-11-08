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
};

#endif
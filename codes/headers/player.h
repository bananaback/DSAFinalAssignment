#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"
#include "game.h"
#include "animation.h"

class Player : public GameObject {
public:
	Player(float x, float y, float width, float height, float speed, float healthPoint, Game& game);
	~Player();
	void update(Game& game);
	void draw(Game& game);
private:
	float _speed, _healthPoint, _assetWidth, _assetHeight, _scaleX, _scaleY, _angle;
	int _assetName[9] = { 0, 2, 4, 2, 0, 1, 3, 1, 0 };
	sf::Vector2i moveVec;
	std::vector<std::shared_ptr<Animation>> _animations;
	int _currentAnimation;
	sf::Sprite _gun;
};

#endif
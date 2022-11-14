#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"
#include "game.h"

class Player : public GameObject {
public:
	Player(float x, float y, float width, float height, float speed, float healthPoint);
	~Player();
	void update(Game& game);
	void draw(Game& game);
private:
	float _speed, _healthPoint;
	sf::Vector2i moveVec;
};

#endif
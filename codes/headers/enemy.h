#pragma once
#ifndef  ENEMY_H
#define ENEMY_H

#include "gameobject.h"
#include "game.h"

class Enemy : public GameObject {
public:
	Enemy(float x, float y, float width, float height, float speed, float attackDamage, float healthPoint);
	~Enemy();
	void update(Game& game, float pX, float pY);
	void draw(Game& game);
	float getHealth();
	void setHealth(float h);
private:
	float _speed, _attackDamage, _healthPoint, _angle;
};

#endif // ! ENEMY_H

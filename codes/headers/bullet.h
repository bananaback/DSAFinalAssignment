#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "gameobject.h"

class Bullet : public GameObject {
public:
	Bullet(float x, float y, float width, float height, float speed, float damage);
	~Bullet();
	void update(Game& game);
	void draw(Game& game);
private:
	float _speed;
	float _damage;
};

#endif
#pragma once
#ifndef  BULLET_H
#define BULLET_H

#include "gameobject.h"
#include "game.h"

class Bullet : public GameObject {
public:
	Bullet(float x, float y, float width, float height, float speed, float damage, float angle);
	~Bullet();
	void update(Game& game);
	void draw(Game& game);
	float getDamage();
private:
	float _speed, _damage, _angle, _timer, _lifeTime;
};

#endif // ! BULLET_H


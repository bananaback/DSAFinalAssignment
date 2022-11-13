#pragma once
#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "bullet.h"

class PlayerBullet : public Bullet {
public:
	PlayerBullet(float x, float y, float width, float height, float speed, float damage);
	~PlayerBullet();
	void update(Game& game);
	void draw(Game& game);
};

#endif
#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"
#include "wall.h"
#include "spawner.h"
class Character : public GameObject {
public:
	Character(float x, float y, float width, float height);
	~Character();
	void resolveCollisionWithWall(Wall& wall, int offset), resolveCollisionWithSpawner(Spawner& spawner, int offset);
	void resetMove();
protected:
	bool canGoUp, canGoDown, canGoLeft, canGoRight;
};

#endif
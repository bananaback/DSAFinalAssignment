#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"
#include "wall.h"
class Character : public GameObject {
public:
	Character(float x, float y, float width, float height);
	~Character();
	void resolveCollisionWithWall(Wall& wall, int offset);
	void resetMove();
protected:
	bool canGoUp, canGoDown, canGoLeft, canGoRight;
};

#endif
#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "game.h"

class GameObject {
public:
	GameObject(float x, float y);
	virtual void update(Game& game);
	virtual void draw(Game& game);
	virtual void getHit();
	float getX();
	float getY();
	float getWidth(), getHeight();
	float getNextX();
	float getNextY();
	void setX(float x);
	void setY(float y);
	bool isDead();
	std::shared_ptr<GameObject> _prev, _next;
protected:
	float _x, _y, _width, _height;
	bool _dead;
	float _nextX, _nextY;
	
};

#endif // ! GAMEOBJECT_H


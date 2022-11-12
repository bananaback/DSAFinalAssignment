#pragma once
#ifndef UNIT_H
#define UNTI_H

#include "game.h"

class Unit {
public:
	Unit(float x, float y);
	virtual void update(Game& game);
	virtual void draw(Game& game);
	float getX();
	float getY();
	float getNextX();
	float getNextY();
	void setX(float x);
	void setY(float y);
	std::shared_ptr<Unit> _prev, _next;
	bool _dead;
protected:
	float _x, _y;
	float _nextX, _nextY;
	
};

#endif // ! UNIT_H


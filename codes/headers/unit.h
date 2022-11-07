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
	void setX(float x);
	void setY(float y);
	std::shared_ptr<Unit> _prev, _next;
protected:
	float _x, _y;
};

#endif // ! UNIT_H


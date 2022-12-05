#pragma once
#ifndef DUST_H
#define DUST_H

#include "effect.h"

class Dust : public Effect {
public:
	Dust(float x, float y, float width, float height, Game& game);
	~Dust();
	void update(Game& game);
	void draw(Game& game);
};

#endif // !DUST_H

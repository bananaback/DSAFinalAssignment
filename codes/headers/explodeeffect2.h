#pragma once
#ifndef EXPLODEEFFECT2_H
#define EXPLODEEFFECT2_H

#include "effect.h"

class ExplodeEffect2 : public Effect {
public:
	ExplodeEffect2(float x, float y, float width, float height, Game& game);
	~ExplodeEffect2();
	void update(Game& game);
	void draw(Game& game);
};

#endif 
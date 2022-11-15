#pragma once
#ifndef EXPLOSIONEFFECT2_H
#define EXPLOSIONEFFECT2_H

#include "effect.h"

class ExplosionEffect2 : public Effect {
public:
	ExplosionEffect2(float x, float y, float width, float height, Game& game);
	~ExplosionEffect2();
	void update(Game& game);
	void draw(Game& game);
};

#endif 
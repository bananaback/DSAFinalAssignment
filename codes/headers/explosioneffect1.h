#pragma once
#ifndef EXPLOSIONEFFECT1_H
#define EXPLOSIONEFFECT1_H

#include "effect.h"

class ExplosionEffect1 : public Effect {
public:
	ExplosionEffect1(float x, float y, float width, float height, Game& game);
	~ExplosionEffect1();
	void update(Game& game);
	void draw(Game& game);
};

#endif // ! EXPLOSIONEFFECT1_H

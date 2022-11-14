#pragma once
#ifndef EXPLODE1EFFECT_H
#define EXPLODE1EFFECT_H

#include "effect.h"

class Explode1Effect : public Effect {
public:
	Explode1Effect(float x, float y, float width, float height, Game& game);
	~Explode1Effect();
	void update(Game& game);
	void draw(Game& game);
};

#endif // ! EXPLODE1EFFECT_H

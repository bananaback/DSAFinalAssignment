#pragma once
#ifndef FLAMEEFFECT_H
#define FLAMEEFFECT_H

#include "effect.h"

class FlameEffect : public Effect {
public:
	FlameEffect(float x, float y, float width, float height, Game& game);
	~FlameEffect();
	void update(Game& game);
	void draw(Game& game);
};

#endif // !FLAMEEFFECT_H

#pragma once
#ifndef TOMATOEFFECT_H
#define TOMATOEFFECT_H

#include "effect.h"

class TomatoEffect : public Effect {
public:
	TomatoEffect(float x, float y, float width, float height, Game& game);
	~TomatoEffect();
	void update(Game& game);
	void draw(Game& game);
};

#endif // !TOMATOEFFECT_H

#pragma once
#ifndef ONIONEFFECT_H
#define ONIONEFFECT_H

#include "effect.h"

class OnionEffect : public Effect {
public:
	OnionEffect(float x, float y, float width, float height, Game& game);
	~OnionEffect();
	void update(Game& game);
	void draw(Game& game);
};

#endif // !ONIONEFFECT_H

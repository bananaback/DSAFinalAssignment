#pragma once
#ifndef EFFECT_H
#define EFFECT_H
#include "gameobject.h"
#include "game.h"
#include "animation.h"
class Effect : public GameObject {
public:
	Effect(float x, float y, float width, float height, Game& game);
	~Effect();
	void update(Game& game);
	void draw(Game& game);
protected:
	std::shared_ptr<Animation> _holdingAnimation;
};

#endif // !EFFECT_H

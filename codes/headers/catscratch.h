#pragma once
#ifndef CATSCRATCH_H
#define CATSCRATCH_H

#include "effect.h"

class CatScratch : public Effect {
public:
	CatScratch(float x, float y, float width, float height, Game& game);
	~CatScratch();
	void update(Game& game);
	void draw(Game& game);
};

#endif // !CATSCRATCH_H

#pragma once
#ifndef FLAMETHROWER_H
#define FLAMETHROWER_H
#include "weapon.h"

class FlameThrower : public Weapon {
public:
	FlameThrower(Game& game, float x, float y, float scale);
	~FlameThrower();
	void update(Game& game, float angle, float playerCenterX, float playerCenterY) override;
	void draw(Game& game) override;
};

#endif // ! FLAMETHROWER_H


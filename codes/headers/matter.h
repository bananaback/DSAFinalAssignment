#pragma once
#ifndef MATTER_H
#define MATTER_H
#include "weapon.h"

class Matter : public Weapon {
public:
	Matter(Game& game, float x, float y, float scale);
	~Matter();
	void update(Game& game, float angle, float playerCenterX, float playerCenterY) override;
	void draw(Game& game) override;
};

#endif // ! MATTER_H
#pragma once
#ifndef MGGUN_H
#define MGGUN_H
#include "weapon.h"

class MgGun : public Weapon {
public:
	MgGun(Game& game, float x, float y, float scale);
	~MgGun();
	void update(Game& game, float angle, float playerCenterX, float playerCenterY) override;
	void draw(Game& game) override;
};

#endif // ! MGGUN_H
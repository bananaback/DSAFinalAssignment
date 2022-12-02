#pragma once
#ifndef CANNON_H
#define CANNON_H

#include "weapon.h"

class Cannon : public Weapon {
public:
	Cannon(Game& game, float x, float y, float scale);
	~Cannon();
	void update(Game& game, float angle, float playerCenterX, float playerCenterY) override;
	void draw(Game& game) override;
private:

};

#endif // ! CANNONDISPLAY_H

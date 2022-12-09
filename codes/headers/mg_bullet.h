#pragma once
#ifndef MG_BULLET_H
#define MG_BULLET_H

#include "player_bullet.h"

class MgBullet : public PlayerBullet {
public:
	MgBullet(Game& game, float x, float y, float width, float height, float angle);
	~MgBullet();
	void update(Game& game) override;
	void draw(Game& game) override;
	void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game);
	static int getFrameWidth() { return 11; };
	static int getFrameHeight() { return 8; };
private:
	float _displayAngle;
};

#endif // !MG_BULLET_H

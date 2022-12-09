#pragma once
#ifndef ONION_BULLET_H
#define ONION_BULLET_H

#include "player_bullet.h"

class OnionBullet : public PlayerBullet {
public:
	OnionBullet(Game& game, float x, float y, float width, float height, float angle);
	~OnionBullet();
	void update(Game& game) override;
	void draw(Game& game) override;
	void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game);
	static int getFrameWidth() { return 13; };
	static int getFrameHeight() { return 13; };
private:
	float _displayAngle, _scaleY, _spinDir;
};

#endif // !ONION_BULLET_H
#pragma once
#ifndef CAT_BULLET_H
#define CAT_BULLET_H

#include "player_bullet.h"

class CatBullet : public PlayerBullet {
public:
	CatBullet(Game& game, float x, float y, float width, float height, float angle);
	~CatBullet();
	void update(Game& game) override;
	void draw(Game& game) override;
	void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game);
	static int getFrameWidth() { return 19; };
	static int getFrameHeight() { return 14; };
private:
	float _displayAngle, _scaleY, _spinDir;
};

#endif // !CAT_BULLET_H
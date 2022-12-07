#pragma once
#ifndef TOMATOBULLET_H
#define TOMATOBULLET_H

#include "playerbullet.h"

class TomatoBullet : public PlayerBullet {
public:
	TomatoBullet(Game& game, float x, float y, float width, float height, float angle);
	~TomatoBullet();
	void update(Game& game) override;
	void draw(Game& game) override;
	void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game);
	static int getFrameWidth() { return 11; };
	static int getFrameHeight() { return 12; };
private:
	float _displayAngle, _scaleY, _spinDir;
};

#endif // !TOMATOBULLET_H
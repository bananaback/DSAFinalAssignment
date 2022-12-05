#pragma once
#ifndef CATBULLET_H
#define CATBULLET_H

#include "playerbullet.h"

class CatBullet : public PlayerBullet {
public:
	CatBullet(Game& game, float x, float y, float width, float height, float angle);
	~CatBullet();
	void update(Game& game) override;
	void draw(Game& game) override;
	void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game);
private:
	float _displayAngle, _scaleY, _spinDir;
};

#endif // !CATBULLET_H
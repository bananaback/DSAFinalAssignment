#pragma once
#ifndef FLAMETHROWERBULLET_H
#define FLAMETHROWERBULLET_H

#include "playerbullet.h"

class FlameThrowerBullet : public PlayerBullet {
public:
	FlameThrowerBullet(Game& game, float x, float y, float width, float height, float angle);
	~FlameThrowerBullet();
	void update(Game& game) override;
	void draw(Game& game) override;
	void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game);
};

#endif // FLAMETHROWERBULLET_H

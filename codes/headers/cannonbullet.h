#pragma once
#ifndef CANNONBULLET_H
#define CANNONBULLET_H

#include "playerbullet.h"

class CannonBullet : public PlayerBullet {
public:
	CannonBullet(Game& game, float x, float y, float width, float height, float angle);
	~CannonBullet();
	void update(Game& game) override;
	void draw(Game& game) override;
	void addEffect(std::vector<std::shared_ptr<Effect>>& effect, Game& game);
private:

};

#endif // !CANNONBULLET_H

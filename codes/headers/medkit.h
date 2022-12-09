#pragma once
#ifndef MEDKIT_H
#define MEDKIT_H

#include "collectableitem.h"
#include "game.h"

class Medkit : public CollectableItem {
public:
	Medkit(float x, float y, float width, float height, Game& game);
	~Medkit();
	void update(Game& game, float playerCenterX, float playerCenterY);
	void draw(Game& game) override;
	void activate(Player& player) override;
private:
	double _regenValue;
};

#endif
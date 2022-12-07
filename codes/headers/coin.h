#pragma once
#ifndef COIN_H
#define COIN_H

#include "game.h"
#include "collectableitem.h"

class Coin : public CollectableItem {
public:
	Coin(float x, float y, float width, float height, Game& game);
	~Coin();
	void update(Game& game, float playerCenterX, float playerCenterY) override;
	void draw(Game& game) override;
	void activate(Player& player) override;
private:
	int _value;
	float _timer, _flickerTimer, _flickInterval;
	bool _display;
};

#endif

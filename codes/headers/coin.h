#pragma once
#ifndef COIN_H
#define COIN_H

#include "game.h"
#include "collectableitem.h"

class Coin : public CollectableItem {
public:
	Coin(float x, float y, float width, float height, Game& game);
	~Coin();
	void update(Game& game);
	void draw(Game& game);
private:

};

#endif
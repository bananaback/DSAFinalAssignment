#pragma once
#ifndef COLLECTABLEITEM_H
#define COLLECTABLEITEM_H
#include "gameobject.h"
#include "game.h"
#include "animation.h"
#include "player.h"
class CollectableItem : public GameObject {
public:
	CollectableItem(float x, float y, float width, float height, Game& game);
	~CollectableItem();
	void update(Game& game);
	void draw(Game& game);
	virtual void activate(Player& player) = 0;
protected:
	float _scaleX, _scaleY;
	std::shared_ptr<Animation> _animation;

};
#endif // !COLLECTABLEITEM_H


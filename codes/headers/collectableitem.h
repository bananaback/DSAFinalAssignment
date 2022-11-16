#pragma once
#ifndef COLLECTABLEITEM_H
#define COLLECTABLEITEM_H
#include "gameobject.h"
#include "game.h"
#include "animation.h"
class CollectableItem : public GameObject{
public:
	CollectableItem(float x, float y, float width, float height, Game& game);
	~CollectableItem();
	void update(Game& game);
	void draw(Game& game);
protected:
	float _scaleX, _scaleY;
	std::shared_ptr<Animation> _animation;

};
#endif // !COLLECTABLEITEM_H


#pragma once
#ifndef COLLECTABLEITEM_H
#define COLLECTABLEITEM_H
#include "gameobject.h"
#include "game.h"
#include "animation.h"
#include "player.h"
#include "effect.h"
class CollectableItem : public GameObject {
public:
	CollectableItem(float x, float y, float width, float height, Game& game);
	~CollectableItem();
	virtual void update(Game& game, float playerCenterX, float playerCenterY) = 0;
	virtual void draw(Game& game) = 0;
	void updateAnim(Game& game);
	void drawAnim(Game& game);
	void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game);
	virtual void activate(Player& player) = 0;
protected:
	float _scaleX, _scaleY;
	std::shared_ptr<Animation> _animation;
};
#endif // !COLLECTABLEITEM_H

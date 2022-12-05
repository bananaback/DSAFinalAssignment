#pragma once
#ifndef  PLAYERBULLET_H
#define PLAYERBULLET_H

#include "gameobject.h"
#include "game.h"
#include "animation.h"
#include "effect.h"

class PlayerBullet : public GameObject {
public:
	PlayerBullet(Game& game, float x, float y, float width, float height, float angle);
	~PlayerBullet();
	virtual void update(Game& game) = 0;
	virtual void draw(Game& game) = 0;
	virtual void addEffect(std::vector<std::shared_ptr<Effect>>& effectList, Game& game) = 0;
	void reduceDurability(int d);
	int getDurabilityReduceAmount();
	int getDurability();
	float getDamage();
protected:
	float _angle, _speed, _damageDeal, _timer, _durability, _durabilityReduceAmount;
	std::shared_ptr<Animation> _animation;
};

#endif // ! PLAYERBULLET_H

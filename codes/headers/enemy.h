#pragma once
#ifndef  ENEMY_H
#define ENEMY_H

#include "gameobject.h"
#include "game.h"
#include "animation.h"

class Enemy : public GameObject {
public:
	Enemy(float x, float y, float width, float height, float speed, float attackDamage, float healthPoint, Game& game);
	~Enemy();
	void update(Game& game, float pX, float pY);
	void draw(Game& game);
	float getHealth();
	void setHealth(float h);
	void takeDamage(float d);
	void setUp(bool b), setDown(bool b), setLeft(bool b), setRight(bool b);
	bool isArrived(float x, float y);
	std::vector<std::pair<int, int>> _path;
	void setX(float x), setY(float y);
private:
	float _speed, _attackDamage, _healthPoint, _angle, _assetWidth, _assetHeight, _scaleX, _scaleY;
	std::vector<std::shared_ptr<Animation>> _animations;
	int _currentAnimation = 0;
	bool _canGoUp, _canGoDown, _canGoLeft, _canGoRight;
	
};

#endif // ! ENEMY_H

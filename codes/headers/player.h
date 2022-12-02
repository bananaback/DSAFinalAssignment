#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "animation.h"
#include "character.h"
#include "cannon.h"

class Player : public Character {
public:
	Player(float x, float y, float width, float height, float speed, float healthPoint, Game& game);
	~Player();
	void update(Game& game);
	void draw(Game& game);
	void setCoin(int c);
	int getCoin();
	void takeDamage(float d);
	float getHealth();
	void setHealth(float h);
	void increaseCoin(int amount);
	void increaseHealth(double regenValue);
	void setX(float x), setY(float y);
	void setUp(bool b), setDown(bool b), setLeft(bool b), setRight(bool b);
	float getSpeed();
private:
	float _speed, _healthPoint, _assetWidth, _assetHeight, _scaleX, _scaleY, _angle, _hurting, _hurtTimer;
	int _assetName[9] = { 0, 2, 4, 2, 0, 1, 3, 1, 0 };
	sf::Vector2i moveVec;
	std::vector<std::shared_ptr<Animation>> _animations;
	std::vector<std::shared_ptr<Weapon>> _weaponDisplayList;
	int _currentAnimation, _coin;
	sf::Sprite _gun;
	bool _appear;
};

#endif
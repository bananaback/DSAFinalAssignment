#pragma once
#ifndef SPAWNER_H
#define SPAWNER_H

#include "game.h"
#include "gameobject.h"

class Spawner : public GameObject{
public:
	Spawner(Game& game, float x, float y, std::vector<std::pair<int, std::string>> spawnScript);
	~Spawner();
	void update(Game& game);
	void draw(Game& game);
	float getHealthPoint();
	void setHealthPoint(float f);
	void drawHealthBar(Game& game);
	void takeDamage(float d);
private:
	sf::Sprite _sprite;
	float _healthPoint;
};

#endif
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
	std::pair<bool, std::string> checkSpawn(float timer);
	size_t getQueueLength();
	void generateSpawnQueue(Game& game, float timer);
	void setScale(float s);
private:
	sf::Sprite _sprite;
	float _healthPoint, _spawnScale, _spawnMinScale;
	std::vector<std::pair<int, std::string>> _spawnScript;
};

#endif
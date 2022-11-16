#pragma once
#ifndef  MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include "enemy.h"
#include "player.h"
#include "bullet.h"
#include "effect.h"
#include "collectableitem.h"
#include "wall.h"

class Map {
public:
	Map();
	~Map();
	void updateAll(Game& game);
	void drawAll(Game& game);

	std::vector<std::shared_ptr<Enemy>> enemyList;
	std::vector<std::shared_ptr<Player>> playerList;
	std::vector<std::shared_ptr<Bullet>> bulletList;
	std::vector<std::shared_ptr<Effect>> effectList;
	std::vector<std::shared_ptr<CollectableItem>> collectableItemList;
	std::vector<std::shared_ptr<Wall>> wallList;
};

#endif // ! MAP_H

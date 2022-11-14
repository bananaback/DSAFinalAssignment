#include "../headers/map.h"
#include "../headers/calculator.h"
#include <iostream>
Map::Map() {
	std::cout << "I'm map\n";
}

Map::~Map() {

}

void Map::updateAll(Game& game) {
	// collision check O(mn+np+pq)
		// bullet and enemy
	for (size_t i = 0; i < bulletList.size(); i++) {
		std::shared_ptr<Bullet> bullet = bulletList[i];
		for (size_t j = 0; j < enemyList.size(); j++) {
			std::shared_ptr<Enemy> enemy = enemyList[j];
			if (AABBVsAABB(bullet->getX(), bullet->getY(), bullet->getX() + bullet->getWidth(), bullet->getY() + bullet->getHeight(), enemy->getX(), enemy->getY(), enemy->getX() + enemy->getWidth(), enemy->getY() + enemy->getHeight()) ) {
				enemy->setHealth(enemy->getHealth() - bullet->getDamage());
				std::cout << "Enemy health point: " << enemy->getHealth() << "\n";
				bullet->setDestroy(true);
				break;
			}
		}
	}


	// update
	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->update(game);
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->update(game, playerList[0]->getX() + playerList[0]->getWidth()/2, playerList[0]->getY() + playerList[0]->getHeight()/2);
	for (size_t i = 0; i < bulletList.size(); i++) bulletList[i]->update(game);

	// clear destroyed object
	auto it = bulletList.end();
	while (it > bulletList.begin())
	{
		it--;
		if ((*it)->isDestroyed()) {
			*it = nullptr;
			it = bulletList.erase(it);
		}
	}

	auto it2 = enemyList.end();
	while (it2 > enemyList.begin())
	{
		it2--;
		if ((*it2)->isDestroyed()) {
			*it2 = nullptr;
			it2 = enemyList.erase(it2);
		}
	}
}

void Map::drawAll(Game& game) {
	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->draw(game);
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->draw(game);
	for (size_t i = 0; i < bulletList.size(); i++) bulletList[i]->draw(game);
}
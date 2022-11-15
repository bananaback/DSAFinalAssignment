#include "../headers/map.h"
#include "../headers/calculator.h"
#include "../headers/explosioneffect1.h"
#include "../headers/explosioneffect2.h"
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
				if (enemy->getHealth() <= 0)
				{
					collectableItemList.push_back(std::make_shared<CollectableItem>(enemy->getX()+20, enemy->getY()+5, 16, 16, game));
					collectableItemList.push_back(std::make_shared<CollectableItem>(enemy->getX()+40, enemy->getY()+15, 16, 16, game));
					collectableItemList.push_back(std::make_shared<CollectableItem>(enemy->getX()+60, enemy->getY()+20, 16, 16, game));
					collectableItemList.push_back(std::make_shared<CollectableItem>(enemy->getX()+80, enemy->getY()+30, 16, 16, game));
					collectableItemList.push_back(std::make_shared<CollectableItem>(enemy->getX()+60, enemy->getY()+40, 16, 16, game));
				}
				std::cout << "Enemy health point: " << enemy->getHealth() << "\n";
				bullet->setDestroy(true);
				effectList.push_back(std::make_shared<ExplosionEffect2>(bullet->getX(), bullet->getY(), bullet->getWidth(), bullet->getHeight(), game));
				break;
			}
		}
	}

	for (size_t i = 0; i < collectableItemList.size(); i++) {
		std::shared_ptr<CollectableItem> collectableitem = collectableItemList[i];
		for (size_t j = 0; j < playerList.size(); j++) {
			std::shared_ptr<Player> player = playerList[i];
			if (AABBVsAABB(collectableitem->getX(), collectableitem->getY(), collectableitem->getX() + collectableitem->getWidth(), collectableitem->getY() + collectableitem->getHeight(), player->getX(), player->getY(), player->getX() + player->getWidth(), player->getY() + player->getHeight())) {
				collectableitem->setDestroy(true);
				int c = player->getCoin()+1;
				player->setCoin(c);
			}
		}
	}

	// update
	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->update(game);
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->update(game, playerList[0]->getX() + playerList[0]->getWidth()/2, playerList[0]->getY() + playerList[0]->getHeight()/2);
	for (size_t i = 0; i < bulletList.size(); i++) bulletList[i]->update(game);
	for (size_t i = 0; i < effectList.size(); i++) effectList[i]->update(game);
	for (size_t i = 0; i < collectableItemList.size(); i++) collectableItemList[i]->update(game);


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

	auto it3 = effectList.end();
	while (it3 > effectList.begin()) {
		it3--;
		if ((*it3)->isDestroyed()) {
			it3 = effectList.erase(it3);
		}
	}

	auto it4 = collectableItemList.end();
	while (it4 > collectableItemList.begin())
	{
		it4--;
		if ((*it4)->isDestroyed()) {
			*it4 = nullptr;
			it4 = collectableItemList.erase(it4);
		}
	}
}

void Map::drawAll(Game& game) {
	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->draw(game);
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->draw(game);
	for (size_t i = 0; i < bulletList.size(); i++) bulletList[i]->draw(game);
	for (size_t i = 0; i < effectList.size(); i++) effectList[i]->draw(game);
	for (size_t i = 0; i < collectableItemList.size(); i++) collectableItemList[i]->draw(game);
}
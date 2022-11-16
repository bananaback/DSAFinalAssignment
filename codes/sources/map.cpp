#include "../headers/map.h"
#include "../headers/calculator.h"
#include "../headers/explosioneffect1.h"
#include "../headers/explosioneffect2.h"
#include "../headers/coin.h"
#include <iostream>
#include <random>

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 63); // define the range

Map::Map() {
	std::cout << "I'm map\n";
}

Map::~Map() {

}

template <typename T, typename... Args>
void updateList(Game& game, std::vector<std::shared_ptr<T>>& t_list, Args... args) {
	for (size_t i = 0; i < t_list.size(); i++) {
		t_list[i]->update(game, args...);
	}
}

template <typename T>
void removeDestroyedObjects(std::vector<std::shared_ptr<T>>& t_list) {
	auto it = t_list.end();
	while (it > t_list.begin())
	{
		it--;
		if ((*it)->isDestroyed()) {
			*it = nullptr;
			it = t_list.erase(it);
		}
	}
}

void Map::updateAll(Game& game) {
	// collision check O(mn+np+pq...)
		// bullet and enemy
	for (size_t i = 0; i < bulletList.size(); i++) {
		std::shared_ptr<Bullet> bullet = bulletList[i];
		for (size_t j = 0; j < enemyList.size(); j++) {
			std::shared_ptr<Enemy> enemy = enemyList[j];
			if (bullet->checkCollision(*enemy)) {
				enemy->takeDamage(10);
				if (enemy->getHealth() <= 0)
				{
					for (int k = 0; k < 9; k++) collectableItemList.push_back(std::make_shared<Coin>(enemy->getX()+enemy->getWidth()/2 + distr(gen) - 16, enemy->getY() + enemy->getHeight()/2 + distr(gen) - 16, 32, 32, game));
				}
				std::cout << "Enemy health point: " << enemy->getHealth() << "\n";
				bullet->destroy();
				effectList.push_back(std::make_shared<ExplosionEffect1>(bullet->getX(), bullet->getY(), bullet->getWidth(), bullet->getHeight(), game));
				break;
			}
		}
	}

	// player and item
	for (size_t i = 0; i < collectableItemList.size(); i++) {
		std::shared_ptr<CollectableItem> collectableitem = collectableItemList[i];
		for (size_t j = 0; j < playerList.size(); j++) {
			std::shared_ptr<Player> player = playerList[j];
			if (collectableitem->checkCollision(*player)) {
				collectableitem->destroy();
				player->increaseCoin(1);
			}
		}
	}

	// player and enemy
	for (size_t i = 0; i < playerList.size(); i++) {
		std::shared_ptr<Player> player = playerList[i];
		for (size_t j = 0; j < enemyList.size(); j++) {
			std::shared_ptr<Enemy> enemy = enemyList[j];
			if (player->checkCollision(*enemy)) player->takeDamage(20);
		}
	}


	// player and wall collision resolve
	for (size_t i = 0; i < playerList.size(); i++) {
		std::shared_ptr<Player> player = playerList[i];
		player->setUp(true);
		player->setDown(true);
		player->setLeft(true);
		player->setRight(true);

		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			if (checkCollisionBetweenTwoRect(
				player->getX(),
				player->getY() - 2,
				player->getWidth(),
				2,
				wall->getX(), wall->getY(), wall->getWidth(), wall->getHeight())) {
				player->setUp(false);
				break;
			}
		}

		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			if (checkCollisionBetweenTwoRect(
				player->getX(),
				player->getY() + player->getHeight(),
				player->getWidth(),
				2,
				wall->getX(), wall->getY(), wall->getWidth(), wall->getHeight())) {
				player->setDown(false);
				break;
			}
		}

		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			if (checkCollisionBetweenTwoRect(
				player->getX()-2,
				player->getY(),
				2,
				player->getHeight(),
				wall->getX(), wall->getY(), wall->getWidth(), wall->getHeight())) {
				player->setLeft(false);
				break;
			}
		}

		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			if (checkCollisionBetweenTwoRect(
				player->getX() + player->getWidth(),
				player->getY(),
				2,
				player->getHeight(),
				wall->getX(), wall->getY(), wall->getWidth(), wall->getHeight())) {
				player->setRight(false);
				break;
			}
		}
	}

	// update
	updateList(game, playerList);
	updateList(game, enemyList, playerList[0]->getX() + playerList[0]->getWidth() / 2, playerList[0]->getY() + playerList[0]->getHeight() / 2);
	updateList(game, bulletList);
	updateList(game, effectList);
	updateList(game, collectableItemList);
	updateList(game, wallList);

	

	// clear destroyed object
	removeDestroyedObjects(playerList);
	removeDestroyedObjects(bulletList);
	removeDestroyedObjects(enemyList);
	removeDestroyedObjects(effectList);
	removeDestroyedObjects(collectableItemList);
	removeDestroyedObjects(wallList);
}

void Map::drawAll(Game& game) {
	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->draw(game);
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->draw(game);
	for (size_t i = 0; i < bulletList.size(); i++) bulletList[i]->draw(game);
	for (size_t i = 0; i < effectList.size(); i++) effectList[i]->draw(game);
	for (size_t i = 0; i < collectableItemList.size(); i++) collectableItemList[i]->draw(game);
	for (size_t i = 0; i < wallList.size(); i++) wallList[i]->draw(game);
}
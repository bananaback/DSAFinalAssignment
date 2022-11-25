#include <iostream>
#include <random>
#include "../headers/map.h"
#include "../headers/calculator.h"
#include "../headers/explosioneffect1.h"
#include "../headers/explosioneffect2.h"
#include "../headers/coin.h"
#include "../headers/astar.h"
#include "../headers/astarboi.h"
#include "../headers/utility.h"


std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator
std::uniform_int_distribution<> distr(0, 63); // define the range

Map::Map() {
	std::cout << "I'm map\n";
	playerPosInCell.first = 5;
	playerPosInCell.second = 5;
	blockEnemyMap = blockData;
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
	while (it > t_list.begin()) {
		it--;
		if ((*it)->isDestroyed()) {
			*it = nullptr;
			it = t_list.erase(it);
		}
	}
}

template <typename T>
void removeObjects(std::vector<std::shared_ptr<T>>& t_list) {
	auto it = t_list.end();
	while (it > t_list.begin()) {
		it--;
		*it = nullptr;
		it = t_list.erase(it);
	}
}

void Map::addWall(Game& game, int currentLevel) {
	blockData.clear();
	if (currentLevel == 1) {
		std::string map1Path = "./data/map1.txt";
		readMap(map1Path, blockData);
	}

	for (size_t i = 0; i < blockData.size(); i++) {
		for (size_t j = 0; j < blockData[i].size(); j++) {
			if (blockData[i][j] != 0) {
				wallList.push_back(std::make_shared<Wall>(48 * j, 48 * i, 48, 48, game, blockData[i][j]));
			}
		}
	}
}

void Map::addPlayer(Game& game, int currentLevel) {
	float pX, pY;
	if (currentLevel == 1) {
		pX = 300;
		pY = 500;
	}
	// add player
	playerList.push_back(std::make_shared<Player>(pX, pY, 40, 40, 100, 100, game));
}

void Map::addEnemy(Game& game, int currentLevel) {
	if (currentLevel == 1) {
		enemyList.push_back(std::make_shared<Enemy>(48 * 4 + 9, 48 * 4 + 9, 30, 30, 80, 5, 100, game));
		enemyList.push_back(std::make_shared<Enemy>(48 * 4 + 9, 48 * 17 + 9, 30, 30, 80, 5, 100, game));
		enemyList.push_back(std::make_shared<Enemy>(48 * 28 + 9, 48 * 4 + 9, 30, 30, 80, 5, 100, game));
		enemyList.push_back(std::make_shared<Enemy>(48 * 28 + 9, 48 * 17 + 9, 30, 30, 80, 5, 100, game));
	}
}

void Map::build(Game& game, int currentLevel) {
	addWall(game, currentLevel);
	addPlayer(game, currentLevel);
	addEnemy(game, currentLevel);
}

void Map::clear(Game& game) {
	removeObjects(enemyList);
	removeObjects(bulletList);
	removeObjects(effectList);
	removeObjects(collectableItemList);
	removeObjects(wallList);
	removeObjects(playerList);
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
					for (int k = 0; k < 9; k++) collectableItemList.push_back(std::make_shared<Coin>(enemy->getX() + enemy->getWidth() / 2 + distr(gen) - 16, enemy->getY() + enemy->getHeight() / 2 + distr(gen) - 16, 32, 32, game));
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
				collectableitem->activate(*player);
				collectableitem->destroy();
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

	// bullet and wall
	for (size_t i = 0; i < bulletList.size(); i++) {
		std::shared_ptr<Bullet> bullet = bulletList[i];
		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			if (bullet->checkCollision(*wall)) {
				bullet->destroy();
				effectList.push_back(std::make_shared<ExplosionEffect1>(bullet->getX(), bullet->getY(), bullet->getWidth(), bullet->getHeight(), game));
				break;
			}
		}
	}


	// player and wall collision resolve
	for (size_t i = 0; i < playerList.size(); i++) {
		std::shared_ptr<Player> player = playerList[i];
		player->resetMove();
		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			player->resolveCollisionWithWall(*wall, 2);
		}
	}

	// enemy and wall collision resolve
	for (size_t i = 0; i < enemyList.size(); i++) {
		std::shared_ptr<Enemy> enemy = enemyList[i];
		enemy->resetMove();
		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			enemy->resolveCollisionWithWall(*wall, 2);
		}
	}



	// update
	updateList(game, playerList);
	if (playerList.size() >= 1) {
		updateList(game, enemyList, playerList[0]->getX() + playerList[0]->getWidth() / 2,
			playerList[0]->getY() + playerList[0]->getHeight() / 2);
	}
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

	if (playerList.size() >= 1) {
		// enemy pathfinding
		float pCenterX = playerList[0]->getX() + playerList[0]->getWidth() / 2;
		float pCenterY = playerList[0]->getY() + playerList[0]->getHeight() / 2;
		int currentPlayerPosInCellX = (int)std::floor(pCenterX / 48);
		int currentPlayerPosInCellY = (int)std::floor(pCenterY / 48);

		if (currentPlayerPosInCellX != playerPosInCell.second || currentPlayerPosInCellY != playerPosInCell.first) {
			blockEnemyMap = blockData;
			for (size_t i = 0; i < enemyList.size(); i++) {
				float enemyCenterX = enemyList[i]->getX() + enemyList[i]->getWidth() / 2;
				float enemyCenterY = enemyList[i]->getY() + enemyList[i]->getHeight() / 2;
				std::cout << (int)std::floor(enemyCenterY / 48) << "\n";
				blockEnemyMap[(int)std::floor(enemyCenterY / 48)][(int)std::floor(enemyCenterX / 48)] = 1;
			}

			for (size_t i = 0; i < enemyList.size(); i++) {
				//std::cout << "I'm here\n";
				float enemyCenterX = enemyList[i]->getX() + enemyList[i]->getWidth() / 2;
				float enemyCenterY = enemyList[i]->getY() + enemyList[i]->getHeight() / 2;
				enemyList[i]->_path = astar(blockEnemyMap, (int)std::floor(enemyCenterY / 48),
					(int)std::floor(enemyCenterX / 48),
					currentPlayerPosInCellY, currentPlayerPosInCellX);
			}
		}
		// store player position
		playerPosInCell.first = (int)std::floor(pCenterY / 48);
		playerPosInCell.second = (int)std::floor(pCenterX / 48);
	}
}

void Map::drawAll(Game& game) {
	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->draw(game);
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->draw(game);
	for (size_t i = 0; i < bulletList.size(); i++) bulletList[i]->draw(game);
	for (size_t i = 0; i < effectList.size(); i++) effectList[i]->draw(game);
	for (size_t i = 0; i < collectableItemList.size(); i++) collectableItemList[i]->draw(game);
	for (size_t i = 0; i < wallList.size(); i++) wallList[i]->draw(game);

	// for path finding debug
	/*sf::RectangleShape rectangle;
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 32; j++) {
			rectangle.setPosition(sf::Vector2f(j*48, i*48));
			rectangle.setSize(sf::Vector2f(48.f, 48.f));
			rectangle.setFillColor(sf::Color(0, 1, 0, 100));
			rectangle.setOutlineColor(sf::Color(0, 0, 0, 255));
			rectangle.setOutlineThickness(2);
			game._window.draw(rectangle);
		}
	}*/

}
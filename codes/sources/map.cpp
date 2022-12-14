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
#include "../headers/dust.h"
#include "../headers/medkit.h"

std::uniform_int_distribution<> distr(-40, 40); // define the range

Map::Map() {
	playerPosInCell.first = 5;
	playerPosInCell.second = 5;
	blockEnemyMap = blockData;

	singleTile.setOrigin(sf::Vector2f(8.f, 8.f));
	spawnTimer = 0;
	levelFinish = false;
	levelFinishTimer = 0;
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
		/*std::string map1Path = "./data/block/map_2bl.txt";
		readMap(map1Path, blockData);

		std::string backgroundPath = "./data/background/map_2bg.txt";
		readMap(backgroundPath, backgroundData);*/
	}
	std::string mapPath = "./data/block/map" + std::to_string(currentLevel) + ".txt";
	readMap(mapPath, blockData);

	backgroundData.clear();
	std::string backgroundPath = "./data/background/map" + std::to_string(currentLevel) + ".txt";
	readMap(backgroundPath, backgroundData);

	for (size_t i = 0; i < blockData.size(); i++) {
		for (size_t j = 0; j < blockData[i].size(); j++) {
			if (blockData[i][j] != 0) {
				wallList.push_back(std::make_shared<Wall>(48 * j, 48 * i, 48, 48, game, blockData[i][j]-1));
			}
		}
	}
}

std::uniform_int_distribution<> posDistX(0, 31); // define the range
std::uniform_int_distribution<> posDistY(0, 17);

void Map::addPlayer(Game& game, int currentLevel) {
	int currY = posDistY(game.gen);
	int currX = posDistX(game.gen);
	while (blockData[currY][currX] != 0) {
		currY = posDistY(game.gen);
		currX = posDistX(game.gen);
	}
	// add player
	playerList.push_back(std::make_shared<Player>(currX * 48, currY * 48, 40, 40, 100, 100, game));
}

void Map::addEnemy(Game& game, int currentLevel) {
	//if (currentLevel == 1) {
		enemyList.push_back(std::make_shared<Enemy>(48 * 4 + 9, 48 * 4 + 9, 30, 30, 80, 5, 100, game));
		enemyList.push_back(std::make_shared<Enemy>(48 * 4 + 9, 48 * 11 + 9, 30, 30, 80, 5, 100, game));
		enemyList.push_back(std::make_shared<Enemy>(48 * 28 + 9, 48 * 4 + 9, 30, 30, 80, 5, 100, game));
		enemyList.push_back(std::make_shared<Enemy>(48 * 28 + 9, 48 * 11 + 9, 30, 30, 80, 5, 100, game));
	//}
}


void Map::addSpawner(Game& game, int currentLevel) {
	/*if (currentLevel == 1) {
		spawnerList.push_back(std::make_shared<Spawner>(game, 48 * 5, 48 * 5, std::vector<std::pair<int, std::string>>{
		std::make_pair(1, "slime"), std::make_pair(2.1, "slime"), std::make_pair(4, "slime"), std::make_pair(6, "slime")}));
	}*/
	std::vector<std::pair<int, int>> tried;
	for (int i = 0; i < 3; i++) {
		int currX = posDistX(game.gen);
		int currY = posDistY(game.gen);
		bool found = false;
		for (size_t j = 0; j < tried.size(); j++) {
			if (tried[j].first == currY && tried[j].second == currX) {
				found = true;
			}
		}
		while (blockData[currY][currX] != 0 && found == false) {
			currX = posDistX(game.gen);
			currY = posDistY(game.gen);
		}
		tried.push_back(std::make_pair(currY, currX));
		spawnerList.push_back(std::make_shared<Spawner>(game, 48 * currX, 48 * currY, std::vector<std::pair<int, std::string>>()));
	}
}

void Map::build(Game& game, int currentLevel) {
	levelFinish = false;
	levelFinishTimer = 0;
	spawnTimer = 0;
	addWall(game, currentLevel);
	addPlayer(game, currentLevel);
	//addEnemy(game, currentLevel);
	addSpawner(game, currentLevel);
}

void Map::clear(Game& game) {
	removeObjects(enemyList);
	removeObjects(playerBulletList);
	removeObjects(effectList);
	removeObjects(collectableItemList);
	removeObjects(wallList);
	removeObjects(playerList);
	removeObjects(spawnerList);
}

void Map::updateAll(Game& game) {
	// collision check O(mn+np+pq...)
		// bullet and enemy
	for (size_t i = 0; i < playerBulletList.size(); i++) {
		std::shared_ptr<PlayerBullet> playerBullet = playerBulletList[i];
		for (size_t j = 0; j < enemyList.size(); j++) {
			std::shared_ptr<Enemy> enemy = enemyList[j];
			if (playerBullet->checkCollision(*enemy)) {
				enemy->takeDamage(playerBullet->getDamage());
				if (enemy->getHealth() <= 0 && enemy->isDestroyed()==false)
				{
					enemy->destroy();
					for (int k = 0; k < 5; k++) collectableItemList.push_back(std::make_shared<Coin>(enemy->getX() + enemy->getWidth() / 2 + distr(game.gen) - 16, enemy->getY() + enemy->getHeight() / 2 + distr(game.gen) - 16, 32, 32, game));
				}
				playerBullet->reduceDurability(playerBullet->getDurabilityReduceAmount());
				//effectList.push_back(std::make_shared<ExplosionEffect1>(playerBullet->getX(), playerBullet->getY(), playerBullet->getWidth(), playerBullet->getHeight(), game));
				if (playerBullet->getDurability() <= 0) {
					playerBullet->addEffect(effectList, game);
				}
				break;
			}
		}
	}

	// bullet and spawner
	for (size_t i = 0; i < playerBulletList.size(); i++) {
		std::shared_ptr<PlayerBullet> playerBullet = playerBulletList[i];
		for (size_t j = 0; j < spawnerList.size(); j++) {
			std::shared_ptr<Spawner> spawner = spawnerList[j];
			if (playerBullet->checkCollision(*spawner)) {
				spawner->takeDamage(playerBullet->getDamage());
				if (spawner->getHealthPoint() <= 0)
				{
					for (int k = 0; k < 5; k++) collectableItemList.push_back(std::make_shared<Coin>(spawner->getX() + spawner->getWidth() / 2 + distr(game.gen)*0.5 - 16, spawner->getY() + spawner->getHeight() / 2 + distr(game.gen) * 0.5 - 16, 32, 32, game));
					effectList.push_back(std::make_shared<Dust>(spawner->getX()+spawner->getWidth()/2, spawner->getY()+spawner->getHeight()/2, 16, 16, game));
					collectableItemList.push_back(std::make_shared<Medkit>(spawner->getX() + spawner->getWidth() / 2 + distr(game.gen) * 0.5 - 16, spawner->getY() + spawner->getHeight() / 2 + distr(game.gen) * 0.5 - 16, 32, 32, game));
				}
				playerBullet->reduceDurability(playerBullet->getDurabilityReduceAmount());
				if (playerBullet->getDurability() <= 0) {
					playerBullet->addEffect(effectList, game);
				}
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
				collectableitem->addEffect(effectList, game);
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
	for (size_t i = 0; i < playerBulletList.size(); i++) {
		std::shared_ptr<PlayerBullet> playerBullet = playerBulletList[i];
		for (size_t j = 0; j < wallList.size(); j++) {
			std::shared_ptr<Wall> wall = wallList[j];
			if (playerBullet->checkCollision(*wall)) {
				playerBullet->reduceDurability(playerBullet->getDurabilityReduceAmount());
				effectList.push_back(std::make_shared<ExplosionEffect1>(playerBullet->getX() + playerBullet->getWidth()/2,
					playerBullet->getY() + playerBullet->getHeight()/2, 0, 0, game));
				break;
			}
		}
	}

	// bullet disasppear effect
	for (size_t i = 0; i < playerBulletList.size(); i++) {
		std::shared_ptr<PlayerBullet> playerBullet = playerBulletList[i];
		if (playerBullet->getDurability() <= 0) {
			playerBullet->addEffect(effectList, game);
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

	// player and spawner collision resolve
	for (size_t i = 0; i < playerList.size(); i++) {
		std::shared_ptr<Player> player = playerList[i];
		for (size_t j = 0; j < spawnerList.size(); j++) {
			std::shared_ptr<Spawner> spawner = spawnerList[j];
			player->resolveCollisionWithSpawner(*spawner, 2);
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

	spawnTimer += game._dt;
	// check spawner
	for (size_t i = 0; i < spawnerList.size(); i++) {
		std::pair<bool, std::string> spawn = spawnerList[i]->checkSpawn(spawnTimer);
		if (spawn.first) {
			if (spawn.second == "slime") {
				spawnerList[i]->setScale(1.5);
				enemyList.push_back(std::make_shared<Enemy>(spawnerList[i]->getX() + 9, spawnerList[i]->getY() + 9, 30, 30, 80, 5, 100, game));
			}
		}
		if (spawnerList[i]->getQueueLength() == 0) {
			spawnerList[i]->generateSpawnQueue(game, spawnTimer);
		}
	}

	

	// update
	updateList(game, playerList);
	if (playerList.size() >= 1) {
		updateList(game, enemyList, playerList[0]->getX() + playerList[0]->getWidth() / 2,
			playerList[0]->getY() + playerList[0]->getHeight() / 2);
	}
	updateList(game, playerBulletList);
	updateList(game, effectList);
	if (playerList.size() >= 1) {
		updateList(game, collectableItemList, playerList[0]->getX() + playerList[0]->getWidth() / 2,
			playerList[0]->getY() + playerList[0]->getHeight() / 2);
	}
	updateList(game, wallList);
	updateList(game, spawnerList);



	// clear destroyed object
	removeDestroyedObjects(playerList);
	removeDestroyedObjects(playerBulletList);
	removeDestroyedObjects(enemyList);
	removeDestroyedObjects(effectList);
	removeDestroyedObjects(collectableItemList);
	removeDestroyedObjects(wallList);
	removeDestroyedObjects(spawnerList);


	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->limitObjectToScreen();
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->limitObjectToScreen();

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
				blockEnemyMap[(int)std::floor(enemyCenterY / 48)][(int)std::floor(enemyCenterX / 48)] = 1;
			}

			for (size_t i = 0; i < enemyList.size(); i++) {
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

	//check level finish
	if (spawnerList.size() == 0 && enemyList.size() == 0) {
		levelFinishTimer += game._dt;
		if (levelFinishTimer >= 5) {
			levelFinish = true;
		}
	}
}

void Map::drawBackground(Game& game) {
	for (size_t i = 0; i < backgroundData.size(); i++) {
		for (size_t j = 0; j < backgroundData[i].size(); j++) {
			singleTile.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::TILES]);
			singleTile.setTextureRect(game.ra_ptr->_tilesImgRects[backgroundData[i][j]-1]);
			singleTile.setPosition(sf::Vector2f(j*48+24, i*48+24));
			singleTile.setScale(sf::Vector2f(3.f, 3.f));
			game._window.draw(singleTile);
		}
	}
}

void Map::drawAll(Game& game) {
	drawBackground(game);
	for (size_t i = 0; i < playerList.size(); i++) playerList[i]->draw(game);
	for (size_t i = 0; i < enemyList.size(); i++) enemyList[i]->draw(game);
	for (size_t i = 0; i < playerBulletList.size(); i++) playerBulletList[i]->draw(game);
	for (size_t i = 0; i < effectList.size(); i++) effectList[i]->draw(game);
	for (size_t i = 0; i < collectableItemList.size(); i++) collectableItemList[i]->draw(game);
	for (size_t i = 0; i < wallList.size(); i++) wallList[i]->draw(game);
	for (size_t i = 0; i < spawnerList.size(); i++) spawnerList[i]->draw(game);
	if (playerList.size() >= 1) playerList[0]->drawPlayerCoin(game);

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
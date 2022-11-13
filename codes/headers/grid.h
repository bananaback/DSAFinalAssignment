#pragma once
#ifndef GRID_H
#define GRID_H

#include <memory>
#include "game.h"
#include "gameobject.h"

class Grid {
public:
	Grid(Game& game);
	void add(std::shared_ptr<GameObject> unit);
	void move(std::shared_ptr<GameObject> unit, float destX, float destY);
	void checkCollisionInCell(Game& game, int x, int y);
	void updateUnitsInCell(Game &game, int x, int y);
	void updateCells(Game& game);
	void draw(Game& game);

	static const int s_gridWidth = 16; // fixed
	static const int s_gridHeight = 9; // fixed
	static const int s_cellSize = 48*2; // fixed

	static bool checkCollision(std::shared_ptr<GameObject> obj1, std::shared_ptr<GameObject> obj2);
	std::shared_ptr<GameObject> mCells[s_gridHeight][s_gridWidth];
private:
	
	sf::Text countGameObject;
};

#endif
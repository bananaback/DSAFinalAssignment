#pragma once
#ifndef GRID_H
#define GRID_H

#include <memory>
#include "game.h"
#include "unit.h"

class Grid {
public:
	Grid();
	void add(std::shared_ptr<Unit> unit);
	void move(std::shared_ptr<Unit> unit, float destX, float destY);
	void updateUnitsInCell(Game &game, int x, int y);
	void updateCells(Game& game);
	void draw(Game& game);

	static const int s_gridWidth = 16; // fixed
	static const int s_gridHeight = 9; // fixed
	static const int s_cellSize = 48*2; // fixed
private:
	std::shared_ptr<Unit> mCells[s_gridHeight][s_gridWidth];
};

#endif
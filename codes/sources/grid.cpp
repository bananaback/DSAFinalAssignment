#include "../headers/grid.h"
#include <iostream>
#include <cmath>
Grid::Grid() {
    // Clear the grid.
    for (int i = 0; i < s_gridHeight; i++) {
        for (int j = 0; j < s_gridWidth; j++) {
            mCells[i][j] = nullptr;
        }
    }
}

void Grid::add(std::shared_ptr<Unit> unit) {
    // Determine which grid cell it's in.
    int cellX = (int)(std::floor(unit->getX() / Grid::s_cellSize));
    int cellY = (int)(std::floor(unit->getY() / Grid::s_cellSize));

    if (cellY < 0) cellY = 0;
    if (cellX < 0) cellX = 0;
    if (cellY >= Grid::s_gridHeight) cellY = s_gridHeight - 1;
    if (cellX >= Grid::s_gridWidth) cellX = s_gridWidth - 1;

    // Add to the front of list for the cell it's in.
    unit->_prev = nullptr;
    unit->_next = mCells[cellY][cellX];
    mCells[cellY][cellX] = unit;

    if (unit->_next != nullptr)
    {
        unit->_next->_prev = unit;
    }
    // Attention the index of mCells array
}

void Grid::move(std::shared_ptr<Unit> unit, float destX, float destY) {
    // See which cell it was in.
    int oldCellX = (int)(std::floor(unit->getX() / Grid::s_cellSize));
    int oldCellY = (int)(std::floor(unit->getY() / Grid::s_cellSize));

    if (oldCellY < 0) oldCellY = 0;
    if (oldCellX < 0) oldCellX = 0;
    if (oldCellY >= Grid::s_gridHeight) oldCellY = s_gridHeight - 1;
    if (oldCellX >= Grid::s_gridWidth) oldCellX = s_gridWidth - 1;

    // See which cell it's moving to.
    int cellX = (int)(std::floor(destX / Grid::s_cellSize));
    int cellY = (int)(std::floor(destY / Grid::s_cellSize));

    if (cellY < 0) cellY = 0;
    if (cellX < 0) cellX = 0;
    if (cellY >= Grid::s_gridHeight) cellY = s_gridHeight - 1;
    if (cellX >= Grid::s_gridWidth) cellX = s_gridWidth - 1;

    unit->setX(destX);
    unit->setY(destY);

    // If it didn't change cells, we're done.
    if (oldCellX == cellX && oldCellY == cellY) return;

    // Unlink it from the list of its old cell.
    if (unit->_prev != nullptr) {
        unit->_prev->_next = unit->_next;
    }

    if (unit->_next != nullptr) {
        unit->_next->_prev = unit->_prev;
    }

    // If it's the head of a list, remove it.
    if (mCells[oldCellY][oldCellX] == unit) {
        mCells[oldCellY][oldCellX] = unit->_next;
    }

    // Add it back to the grid at its new cell.
    add(unit);
}

void Grid::updateUnitsInCell(Game& game, int x, int y) {
    std::shared_ptr<Unit> unit = mCells[x][y];
    while (unit != nullptr) {
        unit->update(game);
        move(unit, unit->getNextX(), unit->getNextY());
        if (unit->_dead) {
            if (unit->_prev != nullptr) {
                unit->_prev->_next = unit->_next;
            }
            if (unit->_next != nullptr) {
                unit->_next->_prev = unit->_prev;
            }
            if (mCells[x][y] == unit) {
                mCells[x][y] = unit->_next;
            }
            std::cout << unit.use_count() << "\n";
            unit = nullptr;
            break;
        }
        unit = unit->_next;
    }
}

void Grid::updateCells(Game& game) {
    for (int i = 0; i < s_gridHeight; i++) {
        for (int j = 0; j < s_gridWidth; j++) {
            updateUnitsInCell(game, i, j);
        }
    }
}


// ATTENTION, need to sort the list by depth when add new unit to draw thing correctly
void Grid::draw(Game& game) {
    // Test visualization
    for (int i = 0; i < s_gridHeight; i++) {
        for (int j = 0; j < s_gridWidth; j++) {
            int c = 0;
            std::shared_ptr<Unit> unit = mCells[i][j];
            while (unit != nullptr) {
                c++;
                unit = unit->_next;
            }
            unit = nullptr;
            sf::RectangleShape rect(sf::Vector2f(96, 96));
            if (c == 0) {
                rect.setFillColor(sf::Color::Green);
            }
            else {
                rect.setFillColor(sf::Color::Blue);
            }
            rect.setPosition(sf::Vector2f(1.f * j * s_cellSize, 1.f * i * s_cellSize));
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(5.f);
            game._window.draw(rect);
        }
    }

    for (int i = 0; i < s_gridHeight; i++) {
        for (int j = 0; j < s_gridWidth; j++) {
            std::shared_ptr<Unit> unit = mCells[i][j];
            while (unit != nullptr) {
                unit->draw(game);
                unit = unit->_next;
            }
            unit = nullptr;
        }
    }
}

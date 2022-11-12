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

void Grid::add(std::shared_ptr<GameObject> gameObject) {
    // Determine which grid cell it's in.
    int cellX = (int)(std::floor(gameObject->getX() / Grid::s_cellSize));
    int cellY = (int)(std::floor(gameObject->getY() / Grid::s_cellSize));

    if (cellY < 0) cellY = 0;
    if (cellX < 0) cellX = 0;
    if (cellY >= Grid::s_gridHeight) cellY = s_gridHeight - 1;
    if (cellX >= Grid::s_gridWidth) cellX = s_gridWidth - 1;

    // Add to the front of list for the cell it's in.
    gameObject->getPrevGameObject() = nullptr;
    gameObject->getNextGameObject() = mCells[cellY][cellX];
    mCells[cellY][cellX] = gameObject;

    if (gameObject->getNextGameObject() != nullptr)
    {
        gameObject->getNextGameObject()->getPrevGameObject() = gameObject;
    }
    // Attention the index of mCells array
}

void Grid::move(std::shared_ptr<GameObject> gameObject, float destX, float destY) {
    // See which cell it was in.
    int oldCellX = (int)(std::floor(gameObject->getX() / Grid::s_cellSize));
    int oldCellY = (int)(std::floor(gameObject->getY() / Grid::s_cellSize));

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

    gameObject->setX(destX);
    gameObject->setY(destY);

    // If it didn't change cells, we're done.
    if (oldCellX == cellX && oldCellY == cellY) return;

    // Unlink it from the list of its old cell.
    if (gameObject->getPrevGameObject() != nullptr) {
        gameObject->getPrevGameObject()->getNextGameObject() = gameObject->getNextGameObject();
    }

    if (gameObject->getNextGameObject() != nullptr) {
        gameObject->getNextGameObject()->getPrevGameObject() = gameObject->getPrevGameObject();
    }

    // If it's the head of a list, remove it.
    if (mCells[oldCellY][oldCellX] == gameObject) {
        mCells[oldCellY][oldCellX] = gameObject->getNextGameObject();
    }

    // Add it back to the grid at its new cell.
    add(gameObject);
}

void Grid::updateUnitsInCell(Game& game, int x, int y) {
    std::shared_ptr<GameObject> gameObject = mCells[x][y];
    while (gameObject != nullptr) {
        gameObject->update(game);
        move(gameObject, gameObject->getNextX(), gameObject->getNextY());
        // remove object 
        if (gameObject->isDead()) {
            if (gameObject->getPrevGameObject() != nullptr) {
                gameObject->getPrevGameObject()->getNextGameObject() = gameObject->getNextGameObject();
            }
            if (gameObject->getNextGameObject() != nullptr) {
                gameObject->getNextGameObject()->getPrevGameObject() = gameObject->getPrevGameObject();
            }
            if (mCells[x][y] == gameObject) {
                mCells[x][y] = gameObject->getNextGameObject();
            }
            std::cout << gameObject.use_count() << "\n";
            gameObject = nullptr;
            break;
        }
        gameObject = gameObject->getNextGameObject();
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
            std::shared_ptr<GameObject> gameObject = mCells[i][j];
            while (gameObject != nullptr) {
                c++;
                gameObject = gameObject->getNextGameObject();
            }
            gameObject = nullptr;
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
            std::shared_ptr<GameObject> gameObject = mCells[i][j];
            while (gameObject != nullptr) {
                gameObject->draw(game);
                gameObject = gameObject->getNextGameObject();
            }
            gameObject = nullptr;
        }
    }
}

#include "../headers/grid.h"
#include <iostream>
#include <cmath>
Grid::Grid(Game& game) {
    // Clear the grid.
    for (int i = 0; i < s_gridHeight; i++) {
        for (int j = 0; j < s_gridWidth; j++) {
            mCells[i][j] = nullptr;
        }
    }
    countGameObject.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
}

void Grid::add(std::shared_ptr<GameObject> gameObject) {
    // Determine which grid cell it's in.
    int cellX = (int)(std::floor(gameObject->getX() / Grid::s_cellSize));
    int cellY = (int)(std::floor(gameObject->getY() / Grid::s_cellSize));

    if (cellY < 0) cellY = 0;
    if (cellX < 0) cellX = 0;
    if (cellY >= Grid::s_gridHeight) cellY = s_gridHeight - 1;
    if (cellX >= Grid::s_gridWidth) cellX = s_gridWidth - 1;

    /*// Add to the front of list for the cell it's in.
    gameObject->_prev = nullptr;
    gameObject->_next = mCells[cellY][cellX];
    mCells[cellY][cellX] = gameObject;

    if (gameObject->_next != nullptr)
    {
        gameObject->_next->_prev = gameObject;
    }
    // Attention the index of mCells array*/
    if (mCells[cellY][cellX] == nullptr) {
        mCells[cellY][cellX] = gameObject;
    } else {
        mCells[cellY][cellX]->_prev = gameObject;
        gameObject->_next = mCells[cellY][cellX];
        mCells[cellY][cellX] = gameObject;
    }
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
    int newCellX = (int)(std::floor(destX / Grid::s_cellSize));
    int newCellY = (int)(std::floor(destY / Grid::s_cellSize));

    if (newCellY < 0) newCellY = 0;
    if (newCellX < 0) newCellX = 0;
    if (newCellY >= Grid::s_gridHeight) newCellY = s_gridHeight - 1;
    if (newCellX >= Grid::s_gridWidth) newCellX = s_gridWidth - 1;

    gameObject->setX(destX);
    gameObject->setY(destY);

    // If it didn't change cells, we're done.
    if (oldCellX == newCellX && oldCellY == newCellY) return;

    // Unlink it from the list of its old cell.
    if (gameObject->_prev != nullptr) {
        gameObject->_prev->_next = gameObject->_next;
    }

    if (gameObject->_next != nullptr) {
        gameObject->_next->_prev = gameObject->_prev;
    }

    // If it's the head of a list, remove it.
    if (mCells[oldCellY][oldCellX] == gameObject) {
        mCells[oldCellY][oldCellX] = gameObject->_next;
    }

    gameObject->_next = nullptr;
    gameObject->_prev = nullptr;
    // Add it back to the grid at its new cell.
    add(gameObject);
}

void Grid::updateUnitsInCell(Game& game, int x, int y) {
    std::shared_ptr<GameObject> gameObject = mCells[x][y];
    while (gameObject != nullptr) {
        gameObject->update(game);
        move(gameObject, gameObject->getNextX(), gameObject->getNextY());
        // remove object 
        /*if (gameObject->isDead()) {
            if (gameObject->_prev != nullptr) {
                gameObject->_prev->_next = gameObject->_next;
            }
            if (gameObject->_next != nullptr) {
                gameObject->_next->_prev = gameObject->_prev;
            }
            if (mCells[x][y] == gameObject) {
                mCells[x][y] = gameObject->_next;
            }
            std::cout << gameObject.use_count() << "\n";
            gameObject = nullptr;
            break;
        }
        */
        gameObject = gameObject->_next;
    }
}

bool Grid::checkCollision(std::shared_ptr<GameObject> obj1, std::shared_ptr<GameObject> obj2) {
    if (obj1->getX() > obj2->getX() + obj2->getWidth() || obj2->getX() > obj1->getX() + obj1->getWidth()) return false;
    if (obj1->getY() > obj2->getY() + obj2->getHeight() || obj2->getY() > obj1->getY() + obj1->getHeight()) return false;
    return true;
}

void Grid::checkCollisionInCell(Game& game, int x, int y) {
    int guideX[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
    int guideY[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
    std::vector<std::shared_ptr<GameObject>> objectList;
    for (int i = 0; i < 8; i++) {
        int currY = y + guideY[i];
        int currX = x + guideX[i];
        std::shared_ptr<GameObject> currentObject = mCells[x][y];
        while (currentObject != nullptr) {
            objectList.push_back(currentObject);
            currentObject = currentObject->_next;
        }
    }
    for (size_t i = 0; i < objectList.size(); i++) {
        for (size_t j = i+1; j < objectList.size(); j++) {
            if (checkCollision(objectList[i], objectList[j])) {
                objectList[i]->getHit();
                objectList[i]->getHit();
            }
        }
    }
}

void Grid::updateCells(Game& game) {
    for (int i = 0; i < s_gridHeight; i++) {
        for (int j = 0; j < s_gridWidth; j++) {
            //checkCollisionInCell(game, i, j);
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
                gameObject = gameObject->_next;
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

            countGameObject.setString(std::to_string(c));
            countGameObject.setPosition(sf::Vector2f(1.f * j * s_cellSize, 1.f * i * s_cellSize));
            countGameObject.setFillColor(sf::Color::Black);

            game._window.draw(rect);
            game._window.draw(countGameObject);
        }
    }

    for (int i = 0; i < s_gridHeight; i++) {
        for (int j = 0; j < s_gridWidth; j++) {
            std::shared_ptr<GameObject> gameObject = mCells[i][j];
            while (gameObject != nullptr) {
                gameObject->draw(game);
                gameObject = gameObject->_next;
            }
        }
    }
}



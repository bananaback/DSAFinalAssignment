#pragma once
#ifndef WALL_H
#define WALL_H

#include "game.h"
#include "gameobject.h"

class Wall : public GameObject {
public:
	Wall(float x, float y, float width, float height, Game& game, int id);
	~Wall();
	void update(Game& game);
	void draw(Game& game);
	int getId();
private:
	int _id;
	sf::Sprite _sprite;
};

#endif
#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"
#include "game.h"
class Animation {
public:
	Animation();
	Animation(std::shared_ptr<sf::Texture> t, int x, int y, int w, int h, int count, float frameTime, std::string name);
	void update(float& dt);
	void draw(Game& game, float x, float y, float rot, float scaleX, float scaleY, float originX, float originY);
	bool isEnd();

	float _frame, _frameTime, _timer, _w, _h;
	sf::Sprite _sprite;
	std::vector<sf::IntRect> _frames;
	// Animation name
	std::string _name;
	bool _finishOnce;
};

#endif // !ANIMATION_H

#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

class Animation {
public:
	Animation();
	Animation(std::shared_ptr<sf::Texture> t, int x, int y, int w, int h, int count, float frameTime, std::string name);
	void update(float& dt);
	bool isEnd();

	float _frame, _frameTime, _timer;
	sf::Sprite _sprite;
	std::vector<sf::IntRect> _frames;
	// Animation name
	std::string _name;
};

#endif // !ANIMATION_H

#pragma once
#ifndef ENDING_H
#define ENDING_H

#include "gamestate.h"
#include "SFML/Graphics.hpp"

struct FastButton {
	int _x;
	int _y;
	int _width;
	int _height;
	sf::Sprite _btnImg;
	bool _isHover;
	float _scaleX, _scaleY;
	std::string _name;
};

class Ending : public GameState {
public:
	Ending(Game& game);
	~Ending();
	void handleEvents(Game& game);
	void update(Game& game);
	void render(Game& game);
private:
	sf::Sprite _endingBackground;
	sf::Text _endingText;
	std::vector<FastButton> _btnList;
};

#endif
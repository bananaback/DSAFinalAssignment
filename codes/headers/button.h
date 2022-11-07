#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include "game.h"
#include <string>

class Button {
public:
	Button(float x, float y, float width, float height, std::string name);//constructor
	~Button();//Destructor
	void draw(Game &game);
	bool checkHover(Game &game);
	sf::Sprite _btnImg;
	void update();
private:
	float _x, _y;
	float _width, _height;
	float _scaleX, _scaleY;
	std::string _name;
};
#endif
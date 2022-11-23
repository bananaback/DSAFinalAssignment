#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "game.h"


class Button {
public:
	Button(float x, float y, float width, float height, std::string name);//constructor
	~Button();//Destructor
	void draw(Game& game);
	bool checkHover(Game& game);
	sf::Sprite _btnImg;
	void update(Game& game);
	std::string getName();
private:
	float _x, _y;
	float _width, _height;
	float _scaleX, _scaleY;
	float _maxScaleX, _maxScaleY;
	float _minScaleX, _minScaleY;
	float _speed;
	std::string _name;

};
#endif
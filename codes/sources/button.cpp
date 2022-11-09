#include "../headers/button.h"
#include<iostream>
Button::Button(float x, float y, float width, float height, std::string name)
{
	_name = name;
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_scaleX = 2;
	_scaleY = 2;
	_minScaleX = 2;
	_minScaleY = 2;
	_maxScaleX = 3;
	_maxScaleY = 3;
	_speed = 5;
}

Button::~Button()
{
}
std::string Button::getName()
{
	return _name;
}

void Button::draw(Game& game)
{
	if (_name=="play")
	{
		_btnImg.setTexture(*game.ra_ptr->_imageResources["mainmenu"]["play"]);
	}
	else if (_name == "quit")
	{
		_btnImg.setTexture(*game.ra_ptr->_imageResources["mainmenu"]["quit"]);
	}
	else if (_name == "setting")
	{
		_btnImg.setTexture(*game.ra_ptr->_imageResources["mainmenu"]["setting"]);
	}
	_btnImg.setPosition(_x + _width / 2, _y + _height/ 2);
	if (_name == "play")
	{
		_btnImg.setOrigin(49, 18);
	}
	else if (_name == "quit")
	{
		_btnImg.setOrigin(50, 18);
	}
	else if (_name == "setting")
	{
		_btnImg.setOrigin(73, 22);
	}
	_btnImg.setScale(_scaleX, _scaleY);
	game._window.draw(_btnImg);
	
}

bool Button::checkHover(Game &game)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(game._window);
	if (mousePos.x >= _x && mousePos.x <= _x + _width
		&& mousePos.y >= _y && mousePos.y <= _y + _height)
	{
		return true;
	}
	return false;
}
void Button::update(Game & game)
{
	if (checkHover(game))
	{
		if (_scaleX < _maxScaleX)
		{
			_scaleX += _speed * game._dt;
		}
		else
		{
			_scaleX = _maxScaleX;
		}
		if (_scaleY < _maxScaleY)
		{
			_scaleY += _speed * game._dt;
		}
		else
		{
			_scaleY = _maxScaleY;
		}
	}
	else
	{
		if (_scaleX > _minScaleX)
		{
			_scaleX-=_speed*game._dt;
		}
		else
		{
			_scaleX = _minScaleX;
		}

		if (_scaleY > _minScaleY)
		{
			_scaleY -= _speed * game._dt;
		}
		else
		{
			_scaleY = _minScaleY;
		}
	}
}
#include "../headers/button.h"
#include<iostream>
Button::Button(float x, float y, float width, float height, std::string name) {
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

Button::~Button() {

}
std::string Button::getName() {
	return _name;
}

void Button::draw(Game& game) {
	if (_name=="play") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MAINMENU_PLAY]);
	}
	else if (_name == "quit") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MAINMENU_QUIT]);
	}
	else if (_name == "setting") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MAINMENU_SETTING]);
	}
	else if (_name == "credit") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MAINMENU_STAR]);
	}
	else if (_name == "backmainmenu") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::BACK_MAIN_MENU]);
	}
	else if (_name == "cursor_1") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CURSOR_1]);
	}
	else if (_name == "cursor_2") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CURSOR_2]);
	}
	else if (_name == "cursor_3") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CURSOR_3]);
	}
	else if (_name == "cursor_4") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CURSOR_4]);
	}
	else if (_name == "cursor_5") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CURSOR_5]);
	else if (_name == "tryagain") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::TRY_AGAIN]);
	}
	else if (_name == "backtomain") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::BACK_TO_MAIN]);
	}
	else if (_name == "giveup") {
		_btnImg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::GIVE_UP]);
	}
	_btnImg.setPosition(_x + _width / 2, _y + _height/ 2);
	if (_name == "play") {
		_btnImg.setOrigin(49, 18); // a half of sprite size
	}
	else if (_name == "quit") {
		_btnImg.setOrigin(50, 18); // a half of sprite size
	}
	else if (_name == "setting") {
		_btnImg.setOrigin(73, 22); // a half of sprite size
	}
	else if (_name == "credit") {
		_btnImg.setOrigin(19, 17);
	}
	else if (_name == "backmainmenu") {
		_btnImg.setOrigin(15.5, 14);
	}
	else if (_name == "cursor_1") {
		_btnImg.setOrigin(4.5, 5.5);
	}
	else if (_name == "cursor_2") {
		_btnImg.setOrigin(10, 10.5);
	}
	else if (_name == "cursor_3") {
		_btnImg.setOrigin(11.5, 11.5);
	}
	else if (_name == "cursor_4") {
		_btnImg.setOrigin(13.5, 13.5);
	}
	else if (_name == "cursor_5") {
		_btnImg.setOrigin(16.5, 16.5);
	else if (_name == "tryagain") {
		_btnImg.setOrigin(206.5, 128.5);
	}
	else if (_name == "backtomain") {
		_btnImg.setOrigin(206.5, 128.5);
	}
	else if (_name == "giveup") {
		_btnImg.setOrigin(206.5, 128.5);
	}
	_btnImg.setScale(_scaleX, _scaleY);
	game._window.draw(_btnImg);
	
}

bool Button::checkHover(Game &game) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(game._window);
	if (mousePos.x >= _x && mousePos.x <= _x + _width && mousePos.y >= _y && mousePos.y <= _y + _height) {
		return true;
	}
	return false;
}
void Button::update(Game & game) {
	if (checkHover(game)) {
		if (_scaleX < _maxScaleX) {
			_scaleX += _speed * game._dt;
		}
		else {
			_scaleX = _maxScaleX;
		}
		if (_scaleY < _maxScaleY) {
			_scaleY += _speed * game._dt;
		}
		else {
			_scaleY = _maxScaleY;
		}
	}
	else {
		if (_scaleX > _minScaleX) {
			_scaleX-=_speed*game._dt;
		}
		else {
			_scaleX = _minScaleX;
		}

		if (_scaleY > _minScaleY) {
			_scaleY -= _speed * game._dt;
		}
		else {
			_scaleY = _minScaleY;
		}
	}
}
#include "../headers/resource_allocator.h"
#include "../headers/ending.h"
#include "../headers/game.h"

Ending::Ending(Game& game) {
	_endingBackground.setTexture(*game.ra_ptr->_imageResources[IMAGE::ENDING_BG]);
	_endingBackground.setScale(sf::Vector2f(12.f, 10.f));

	_endingText.setFont(*game.ra_ptr->_fontResources[FONT::THALEAHFAT]);
	_endingText.setString("         Congratulations!\nYou have completed the game!\nThank you for playing our game ^^\n\nDo you want to save your score?");
	_endingText.setFillColor(sf::Color::Blue);
	_endingText.setCharacterSize(80);
	_endingText.setPosition(sf::Vector2f(50, 150));

	FastButton yesBtn;
	yesBtn._x = 500;
	yesBtn._y = 600;
	yesBtn._width = 64;
	yesBtn._height = 64;
	yesBtn._btnImg.setTexture(*game.ra_ptr->_imageResources[IMAGE::YES_BTN]);
	yesBtn._isHover = false;
	yesBtn._scaleX = 4;
	yesBtn._scaleY = 4;
	yesBtn._name = "yes";
	yesBtn._btnImg.setOrigin(8, 8);

	FastButton noBtn;
	noBtn._x = 700;
	noBtn._y = 600;
	noBtn._width = 64;
	noBtn._height = 64;
	noBtn._btnImg.setTexture(*game.ra_ptr->_imageResources[IMAGE::NO_BTN]);
	noBtn._isHover = false;
	noBtn._scaleX = 4;
	noBtn._scaleY = 4;
	noBtn._name = "no";
	noBtn._btnImg.setOrigin(8, 8);

	_btnList.push_back(yesBtn);
	_btnList.push_back(noBtn);

	_name = "ending";
}

Ending::~Ending() {

}

void Ending::handleEvents(Game& game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Space) {
				
			}
		}
		if (pEvent.type == sf::Event::MouseButtonReleased)
		{
			if (pEvent.mouseButton.button == sf::Mouse::Left)
			{
				for (size_t i = 0; i < _btnList.size(); i++) {
					if (_btnList[i]._isHover) {
						if (_btnList[i]._name == "yes") {
							game.changeState("saving", 0, 0);
						} else if (_btnList[i]._name == "no") {
							game.changeState("mainmenu", 0, 0);
						}
					}
				}
			}
		}
	}
}

void Ending::update(Game& game) {
	sf::Vector2i mousePos = sf::Mouse::getPosition(game._window);
	for (size_t i = 0; i < _btnList.size(); i++) {
		if (mousePos.x >= _btnList[i]._x && mousePos.x <= _btnList[i]._x + _btnList[i]._width
			&& mousePos.y >= _btnList[i]._y && mousePos.y <= _btnList[i]._y + _btnList[i]._height) {
			_btnList[i]._isHover = true;
		} else {
			_btnList[i]._isHover = false;
		}
		_btnList[i]._btnImg.setPosition(sf::Vector2f(_btnList[i]._x + _btnList[i]._width / 2, _btnList[i]._y + _btnList[i]._height / 2));
		_btnList[i]._btnImg.setScale(sf::Vector2f(_btnList[i]._scaleX, _btnList[i]._scaleY));
		if (_btnList[i]._isHover) {
			if (_btnList[i]._scaleX < 6) {
				_btnList[i]._scaleX += game._dt * 50;
			} else {
				_btnList[i]._scaleX = 6;
			}
			if (_btnList[i]._scaleY < 6) {
				_btnList[i]._scaleY += game._dt * 50;
			}
			else {
				_btnList[i]._scaleY = 6;
			}
		} else {
			if (_btnList[i]._scaleX > 4) {
				_btnList[i]._scaleX -= game._dt * 50;
			}
			else {
				_btnList[i]._scaleX = 4;
			}
			if (_btnList[i]._scaleY > 4) {
				_btnList[i]._scaleY -= game._dt * 50;
			}
			else {
				_btnList[i]._scaleY = 4;
			}
		}
	}
}

void Ending::render(Game& game) {
	game._window.draw(_endingBackground);
	for (size_t i = 0; i < _btnList.size(); i++) {
		game._window.draw(_btnList[i]._btnImg);
		//sf::RectangleShape rect;
		//rect.setPosition(_btnList[i]._x, _btnList[i]._y);
		//rect.setSize(sf::Vector2f(_btnList[i]._width, _btnList[i]._height));
		//rect.setFillColor(sf::Color(255, 255, 255, 100));
		//game._window.draw(rect);
	}
	game._window.draw(_endingText);
}
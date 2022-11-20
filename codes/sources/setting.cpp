#include "../headers/setting.h"
#include <iostream>
#include "../headers/gamestate.h"
#include "../headers/button.h"
//Constructor
Setting::Setting(Game& game) {
	_name = "setting";
	_background.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SETTING_BG]);
	//text cursor
	_mouseCursor.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_mouseCursor.setString("Mouse Cursor");
	_mouseCursor.setScale(sf::Vector2f(2.f, 2.f));
	_mouseCursor.setPosition(sf::Vector2f(200.f, 620.f));
	_mouseCursor.setFillColor(sf::Color(236, 83, 26, 255));
	//background cursor
	_cursorBg.setSize(sf::Vector2f(530.f, 80.f));
	_cursorBg.setFillColor(sf::Color(65, 187, 190, 200));
	_cursorBg.setPosition(sf::Vector2f(595.f, 630.f));
	//button cursor
	_btns.push_back(std::make_shared<Button>(600, 650, 100, 46, "cursor_1"));
	_btns.push_back(std::make_shared<Button>(700, 650, 100, 46, "cursor_2"));
	_btns.push_back(std::make_shared<Button>(800, 650, 100, 46, "cursor_3"));
	_btns.push_back(std::make_shared<Button>(910, 650, 100, 46, "cursor_4"));
	_btns.push_back(std::make_shared<Button>(1020, 650, 100, 46, "cursor_5"));
	
	_backMainMenu = std::make_shared<Button>(50, 50, 31, 28, "backmainmenu");
}

Setting::~Setting()
{
}

void Setting::handleEvents(Game& game)
{
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Space) {
				game.changeState("gameplay");
			}
		}
	}
	if (pEvent.type == sf::Event::MouseButtonReleased) {
		if (pEvent.mouseButton.button == sf::Mouse::Left) if (_backMainMenu->checkHover(game))game.changeState("mainmenu");
	}
}

void Setting::update(Game& game)
{
	_backMainMenu->update(game);
	for (size_t i = 0; i < _btns.size(); i++) {
		_btns[i]->update(game);
	}
}

void Setting::render(Game& game)
{
	_background.setScale(sf::Vector2f(1.1f, 0.9f));
	game._window.draw(_background);
	game._window.draw(_cursorBg);
	game._window.draw(_mouseCursor);
	for (size_t i = 0; i < _btns.size(); i++) {
		_btns[i]->draw(game);
	}
	_backMainMenu->draw(game);
	
}
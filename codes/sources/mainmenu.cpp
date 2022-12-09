#include <iostream>
#include "../headers/mainmenu.h"
#include "../headers/gamestate.h"
#include "../headers/button.h"
// Constructor
MainMenu::MainMenu(Game& game) {
	// init text
	_text.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
	_text.setPosition(280, 350);
	_text.setString("This is main menu!");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	_gameTitle.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_gameTitle.setPosition(500, 180);
	_gameTitle.setString("The shooting");
	_gameTitle.setCharacterSize(120);
	_gameTitle.setFillColor(sf::Color::Black);
	_gameTitle.setStyle(sf::Text::Bold);
	// Set state name to switch soon
	_name = "mainmenu";
	_btns.push_back(std::make_shared<Button>(700, 430, 100, 46, "play"));
	_btns.push_back(std::make_shared<Button>(700, 540, 100, 46, "setting"));
	_btns.push_back(std::make_shared<Button>(700, 650, 100, 46, "quit"));
	_btns.push_back(std::make_shared<Button>(1440, 800, 100, 46, "credit"));
}
// Destructor
MainMenu::~MainMenu() {

};

// Handle game events
void MainMenu::handleEvents(Game& game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Space) {
				game.changeState("gameplay", 0, 0);
			}
		}
	}
	if (pEvent.type == sf::Event::MouseButtonReleased) {
		if (pEvent.mouseButton.button == sf::Mouse::Left) {
			for (size_t i = 0; i < _btns.size(); i++) {
				if (_btns[i]->checkHover(game)) {
					if (_btns[i]->getName() == "play") game.changeState("gameplay", 0, 1);
					if (_btns[i]->getName() == "quit") game.setRunning(false);
					if (_btns[i]->getName() == "credit") game.changeState("credit", 0, 0);
					if (_btns[i]->getName() == "setting") game.changeState("setting", 0, 0);
				}
			}
		}
	}
};
// Update game logic
void MainMenu::update(Game& game) {
	for (size_t i = 0; i < _btns.size(); i++) {
		_btns[i]->update(game);
	}
};
// Render game
void MainMenu::render(Game& game) {
	// Draw the text
	game._window.draw(_text);

	_mainMenuBg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::MAINMENU_BG]);
	_mainMenuBg.setScale(sf::Vector2f(2.4f, 2.f));
	game._window.draw(_mainMenuBg);
	//draw game title
	game._window.draw(_gameTitle);
	for (size_t i = 0; i < _btns.size(); i++) {
		_btns[i]->draw(game);
	}
};
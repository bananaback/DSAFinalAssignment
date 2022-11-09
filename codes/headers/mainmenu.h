#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "game.h"
#include "gamestate.h"
#include "button.h"

// MainMenu class, inherit from GameState
class MainMenu : public GameState {
public:
	// Constructor
	MainMenu(Game &game);
	// Destructor
	~MainMenu();
	// Game event handle
	void handleEvents(Game &game);
	// Update game logic
	void update(Game &game);
	// Render game
	void render(Game &game);
private:
	// Testing text on main menu
	sf::Font _font;
	sf::Font _font2;
	sf::Text _text;
	sf::Text _gameTitle;
	sf::Sprite _mainMenuBg;
	std::vector<std::shared_ptr<Button>> _btns;
};

#endif 
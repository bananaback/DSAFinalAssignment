#pragma once
#ifndef SETTING_H
#define SETTING_H
#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "button.h"
class Setting : public GameState {
public:
	// Constructor
	Setting(Game& game);
	// Destructor
	~Setting();
	// Game event handle
	void handleEvents(Game& game);
	// Update game logic
	void update(Game& game);
	// Render game
	void render(Game& game);
private:
	sf::Sprite _background;
	std::shared_ptr<Button> _backMainMenu;
	std::vector<std::shared_ptr<Button>> _btns;
	sf::RectangleShape _cursorBg;
	sf::Text _mouseCursor;
};
#endif // !SETTING_H

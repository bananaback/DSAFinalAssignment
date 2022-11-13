#pragma once
#ifndef CREDIT_H
#define CREDIT_H
#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "button.h"
class Credit : public GameState {
public:
	// Constructor
	Credit(Game& game);
	// Destructor
	~Credit();
	// Game event handle
	void handleEvents(Game& game);
	// Update game logic
	void update(Game& game);
	// Render game
	void render(Game& game);
private:
	sf::Sprite _background;
	std::shared_ptr<Button> _backMainMenu;
	sf::Text _creditText;
	sf::Text _person1;
	sf::Text _person2;
	sf::Text _person3;
	sf::Text _person4;
};
#endif // !CREDIT_H


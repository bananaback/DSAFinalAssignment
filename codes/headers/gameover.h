#pragma once
#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "button.h"
class GameOver : public GameState {
public:
	// Constructor
	GameOver(Game& game);
	// Destructor
	~GameOver();
	// Game event handle
	void handleEvents(Game& game);
	// Update game logic
	void update(Game& game);
	// Render game
	void render(Game& game);
private:
	sf::Sprite _gameOverbg;
	//std::shared_ptr<Button> _backMainMenu;
	std::vector<std::shared_ptr<Button>> _btns;
	sf::Text _gameOverText;
};
#endif // !CREDIT_H

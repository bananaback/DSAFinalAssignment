#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "game.h"
#include "gamestate.h"
#include "SFML/Graphics.hpp"

class GamePlay : public GameState {
public:
	// Constructor
	GamePlay();
	// Destructor
	~GamePlay();
	// Game play events handler
	void handleEvents(Game &game);
	// Game play logic update
	void update(Game &game);
	// Game play render
	void render(Game &game);

private:
	sf::Font _monoFont;
	sf::Text _text;
};

#endif // !GAMEPLAY_H

#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "game.h"
#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "grid.h"

class GamePlay : public GameState {
public:
	// Constructor
	GamePlay(Game &game);
	// Destructor
	~GamePlay();
	// Game play events handler
	void handleEvents(Game &game);
	// Game play logic update
	void update(Game &game);
	// Game play render
	void render(Game &game);
	std::shared_ptr<Grid> _grid;
private:
	sf::Text _text;
};

#endif // !GAMEPLAY_H

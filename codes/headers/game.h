#pragma once
#ifndef  GAME_H
#define GAME_H

#include <memory>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "gamestate.h"
#include "resourceallocator.h"


// Game class
class Game {
public:
	// Constructor
	Game();
	// Destructor
	~Game();

	// Game run
	void run();
	// Game init
	void init();
	// Function to add new state to game state list
	void addState(std::shared_ptr<GameState> gamestate);
	// Function to change game state
	void changeState(std::string name, bool clear, bool build);
	// Function to end game
	void setRunning(bool r);

	// Pointer to resources 
	std::shared_ptr<ResourceAllocator> ra_ptr;
	// Game window
	sf::RenderWindow _window;

	// This is for delta time
	sf::Clock _clock;
	float _dt;

private:
	// Game logic update
	void update();
	// Game events handler
	void handleEvents();
	// Game render
	void render();
	// Check end game
	void checkQuit();
	// If it false, end game
	bool _running = false;
	// Pointer to current game state
	std::shared_ptr<GameState> _currentState;
	// List of game state
	std::vector<std::shared_ptr<GameState>> _states;
};

#endif // ! GAME_H

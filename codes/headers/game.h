#pragma once
#ifndef  GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "gamestate.h"
#include "resourceallocator.h"
#include <memory>


class Game {
public:
	Game();
	~Game();

	void run();
	void init(std::shared_ptr<GameState> gamestate);
	void addState(std::shared_ptr<GameState> gamestate);
	void changeState(std::string name);
	void setRunning(bool r);

	std::shared_ptr<ResourceAllocator> ra_ptr;
	sf::RenderWindow _window;

private:
	void update();
	void handleEvents();
	void render();
	void checkQuit();
	bool _running = false;
	std::shared_ptr<GameState> _currentState;
	std::vector<std::shared_ptr<GameState>> _states;
};

#endif // ! GAME_H

#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;
// GameState class
class GameState {
public:
	// Virtual function, we will override it soon
	virtual void handleEvents(Game &game) = 0;
	virtual void update(Game &game) = 0;
	virtual void render(Game &game) = 0;
	// Virtual destructor
	virtual  ~GameState(){};
};

#endif // !GAMESTATE_H

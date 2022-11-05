#pragma once
#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;

class GameState {
public:
	virtual void handleEvents(Game &game) = 0;
	virtual void update(Game &game) = 0;
	virtual void render(Game &game) = 0;
	virtual  ~GameState(){};
};

#endif // !GAMESTATE_H

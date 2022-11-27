#pragma once
#ifndef  HIGHSCORE_H
#define HIGHSCORE_H

#include "gamestate.h"
#include "SFML/Graphics.hpp"

class Highscore : public GameState {
public:
	Highscore(Game& game);
	~Highscore();
	void update(Game& game);
	void render(Game& game);
	void handleEvents(Game& game);
private:
	sf::Sprite _highscoreBg;
	sf::Text _highscoreTitle;

};

#endif // ! HIGHSCORE_H

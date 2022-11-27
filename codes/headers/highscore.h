#pragma once
#ifndef  HIGHSCORE_H
#define HIGHSCORE_H

#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "candidateinfor.h"

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
	std::vector<std::shared_ptr<CandidateInfor>> _candidateList;
};

#endif // ! HIGHSCORE_H

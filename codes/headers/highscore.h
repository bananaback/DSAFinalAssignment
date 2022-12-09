#pragma once
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "candidate_info.h"

class Highscore : public GameState {
public:
	Highscore(Game& game);
	~Highscore();
	void update(Game& game);
	void render(Game& game);
	void handleEvents(Game& game);
	void drawText(Game& game, float x, float y, std::string s, float scale);
	void build(Game& game) override;
private:
	sf::Sprite _highscoreBg, _char;
	sf::Text _highscoreTitle;
	std::vector<std::shared_ptr<CandidateInfo>> _candidateList;
};

#endif // ! HIGHSCORE_H

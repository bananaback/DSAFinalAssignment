#pragma once
#ifndef CANDIDATE_INFO_H
#define CANDIDATE_INFO_H

#include "game.h"

class CandidateInfo {
public:
	CandidateInfo(Game& game, float x, float y, std::string name, int score);
	~CandidateInfo();
	void update(Game& game);
	void draw(Game& game);
	std::string getName();
	int getScore();
	float getX();
	float getY();
private:
	float _x, _y, _width, _height;
	std::string _name; 
	int _score;
	sf::Text _text;
};

#endif // ! CANDIDATE_INFO_H

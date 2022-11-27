#pragma once
#ifndef  CANDIDATEINFOR_H
#define CANDIDATEINFOR_H

#include "game.h"

class CandidateInfor {
public:
	CandidateInfor(Game& game, float x, float y, std::string name, int score);
	~CandidateInfor();
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

#endif // ! CANDIDATEINFOR_H

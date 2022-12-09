#pragma once
#ifndef  SAVING_H
#define SAVING_H

#include "gamestate.h"
#include "SFML/Graphics.hpp"

struct TextBox
{
	int _x, _y, _width, _height;
	std::string _currentContext;
	sf::Text _text;
	bool _focus;
};

class Saving : public GameState {
public:
	Saving(Game& game);
	~Saving();
	void update(Game& game);
	void handleEvents(Game& game);
	void render(Game& game);
private:
	sf::Sprite _savingBackground;
	sf::Text _savingText, _tutorText, _scoreText;
	TextBox _userName;
	int _score;
};

#endif // ! SAVING_H

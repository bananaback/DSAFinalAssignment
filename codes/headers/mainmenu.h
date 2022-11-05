#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "game.h"
#include "gamestate.h"

class MainMenu : public GameState {
public:
	MainMenu();
	~MainMenu();
	void handleEvents(Game &game);
	void update(Game &game);
	void render(Game &game);
private:
	sf::Font _font;
	sf::Text _text;
	std::string _name;
};

#endif 
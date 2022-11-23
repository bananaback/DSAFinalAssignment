#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "game.h"
#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "map.h"

class GamePlay : public GameState {
public:
	// Constructor
	GamePlay(Game& game);
	// Destructor
	~GamePlay();
	// Game play events handler
	void handleEvents(Game& game);
	// Game play logic update
	void update(Game& game);
	// Game play render
	void render(Game& game);
	void addPlayerBullet(Game& game);
	void addEnemy(Game& game);
	void drawPlayerHealthBar(Game& game);
private:
	sf::Text _text;
	Map _map;
	sf::RectangleShape _background;
	sf::Sprite _playerHPBarBg, _playerHpBar;
	std::vector<std::vector<int>> _currentBlockMap;
};

#endif // !GAMEPLAY_H

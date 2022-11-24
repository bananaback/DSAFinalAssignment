#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "game.h"
#include "gamestate.h"
#include "SFML/Graphics.hpp"
#include "map.h"
#include "flyingtext.h"
#include "typingtext.h"

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
	void fadeInInit(Game& game), fadeOutInit(Game& game);
	void addWall(Game& game, int currentLevel);
	std::string _state;
private:
	sf::Text _text;
	Map _map;
	sf::RectangleShape _background;
	sf::Sprite _playerHPBarBg, _playerHpBar;

	// fade in/out element
	sf::RectangleShape _backgroundLeft, _backgroundRight, _blackCover;
	float _blackCoverOpacity, _timer, _blX, _brX;
	bool _addReady, _addLevel, _addGo, _addLevelComplete, _addContinue;

	std::vector<std::shared_ptr<FlyingText>> _flyingTextList;
	std::vector<std::shared_ptr<TypingText>> _typingTextList;

	int _currentLevel;
};

#endif // !GAMEPLAY_H

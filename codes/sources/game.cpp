#include <iostream>
#include "../headers/game.h"
#include "../headers/mainmenu.h"
#include "../headers/gameplay.h" 
#include "../headers/credit.h"
#include "../headers/setting.h"
#include "../headers/gameover.h"
#include "../headers/ending.h"
#include "../headers/saving.h"
#include "../headers/highscore.h"

// Constructor
Game::Game() {
	// set running to true
	_running = true;
	// create a new game window
	_window.create(sf::VideoMode(48 * 2 * 16, 48 * 2 * 9), "Infinity topdown shooter game!");
	_window.setMouseCursorVisible(false);
	//_window.setFramerateLimit(60);
	//_window.setVerticalSyncEnabled(true);
	// initialize dt
	_dt = 0;
	gen.seed(rd()); // seed the generator

}
// Destructor
Game::~Game() {

}
// Function to run our game
void Game::run() {
	while (_running) {
		_dt = _clock.restart().asSeconds();
		//do the game 
		update();
		handleEvents();
		render();
		checkQuit();
	}
}
// Function to init our game
void Game::init() {
	// Pointer to resouce allocator 
	std::shared_ptr<ResourceAllocator> resouceAllocator(new ResourceAllocator);
	// Attach resouce allocator to our game
	ra_ptr = resouceAllocator;

	// Pointer to main menu game state
	std::shared_ptr<MainMenu> mainMenu(new MainMenu(*this));
	// Pointer to game play game state
	std::shared_ptr<GamePlay> gamePlay(new GamePlay(*this));
	std::shared_ptr<Credit> credit(new Credit(*this));
	std::shared_ptr<Setting> setting(new Setting(*this));
	std::shared_ptr<GameOver> gameOver(new GameOver(*this));
	std::shared_ptr<Ending> ending(new Ending(*this));
	std::shared_ptr<Saving> saving(new Saving(*this));
	std::shared_ptr<Highscore> highscore(new Highscore(*this));

	addState(mainMenu);
	addState(gamePlay);
	addState(credit);
	addState(setting);
	addState(gameOver);
	addState(ending);
	addState(saving);
	addState(highscore);
	_currentState = mainMenu;
	_cursorImg.setTexture(*ra_ptr->_imageResources[ra_ptr->IMAGE::CURSOR_1]);
	_cursorImg.setScale(2.f, 2.f);
}
// Update game logic
void Game::update() {
	_currentState->update(*this);
}
// Function to set up our game
void Game::setRunning(bool r) {
	_running = r;
}
// Game events handler
void Game::handleEvents() {
	_currentState->handleEvents(*this);
}

void Game::setCursorProperties() {
	_cursorImg.setOrigin(1.f * _cursorImg.getTexture()->getSize().x / 2, 1.f * _cursorImg.getTexture()->getSize().y / 2);
	_cursorImg.setTextureRect(sf::IntRect(0, 0, _cursorImg.getTexture()->getSize().x, _cursorImg.getTexture()->getSize().y));
}

// Game render
void Game::render() {
	_window.clear();
	_currentState->render(*this);

	sf::Vector2i pixelPos = sf::Mouse::getPosition(_window);
	_cursorImg.setPosition(pixelPos.x, pixelPos.y);
	setCursorProperties();
	_window.draw(_cursorImg);

	_window.display();
}
// Function to check if game is end
void Game::checkQuit() {
	if (!_running) _window.close();
}
// Add more game state here
void Game::addState(std::shared_ptr<GameState> gamestate) {
	_states.push_back(gamestate);
}
// Function to switch game state with state name
void Game::changeState(std::string name, bool clear, bool build) {
	if (clear) _currentState->clear(*this);
	for (size_t i = 0; i < _states.size(); i++) {
		if (_states[i]->_name == name) {
			_currentState = _states[i];
		}
	}
	if (build) _currentState->build(*this);
}

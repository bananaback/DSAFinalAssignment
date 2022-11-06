#include "../headers/game.h"

// Constructor
Game::Game() {
	// set running to true
	_running = true;
	// create a new game window
	_window.create(sf::VideoMode(48*2*16, 48*2*9), "Infinity topdown shooter game!");
}
// Destructor
Game::~Game() {

}
// Function to run our game
void Game::run() {
	while (_running) {
		//do the game 
		update();
		handleEvents();
		render();
		checkQuit();
	}
}
// Function to init our game
void Game::init(std::shared_ptr<GameState> gamestate) {
	_currentState = gamestate;
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
// Game render
void Game::render() {
	_window.clear();
	_currentState->render(*this);
	_window.display();
}
// Function to check if game is end
void Game::checkQuit() {
	if (!_running) _window.close();
}
// Add more game state here
void Game::addState(std::shared_ptr<GameState> gamestate) {

}
// Function to switch game state with state name
void Game::changeState(std::string name) {

}

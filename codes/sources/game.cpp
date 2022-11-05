#include "../codes/headers/game.h"

Game::Game() {
	_running = true;
	_window.create(sf::VideoMode(48*2*16, 48*2*9), "Infinity topdown shooter game!");
}

Game::~Game() {

}

void Game::run() {
	while (_running) {
		//do the game 
		update();
		handleEvents();
		render();
		checkQuit();
	}
}

void Game::init(std::shared_ptr<GameState> gamestate) {
	_currentState = gamestate;
}

void Game::update() {
	_currentState->update(*this);
}

void Game::setRunning(bool r) {
	_running = r;
}

void Game::handleEvents() {
	_currentState->handleEvents(*this);
}

void Game::render() {
	_window.clear();
	_currentState->render(*this);
	_window.display();
}

void Game::checkQuit() {
	if (!_running) _window.close();
}

void Game::addState(std::shared_ptr<GameState> gamestate) {

}

void Game::changeState(std::string name) {

}

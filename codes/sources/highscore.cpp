#include "../headers/highscore.h"

#include "../headers/game.h"

Highscore::Highscore(Game& game) {
	_highscoreBg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SCORE_BG]);
	_highscoreBg.setScale(sf::Vector2f(12.f, 10.f));

}

Highscore::~Highscore() {

}

void Highscore::handleEvents(Game& game) {

}

void Highscore::update(Game& game) {

}

void Highscore::render(Game& game) {
	game._window.draw(_highscoreBg);
}


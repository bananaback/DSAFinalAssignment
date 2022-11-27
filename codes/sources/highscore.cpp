#include "../headers/highscore.h"

#include "../headers/game.h"

Highscore::Highscore(Game& game) {
	_highscoreBg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SCORE_BG]);
	_highscoreBg.setScale(sf::Vector2f(12.f, 10.f));

	_highscoreTitle.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_highscoreTitle.setCharacterSize(100);
	_highscoreTitle.setFillColor(sf::Color::Black);
	_highscoreTitle.setPosition(sf::Vector2f(350, 50));
	_highscoreTitle.setString("TOP 10 BEST PLAYER");
}

Highscore::~Highscore() {

}

void Highscore::handleEvents(Game& game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
	}
}

void Highscore::update(Game& game) {

}

void Highscore::render(Game& game) {
	game._window.draw(_highscoreBg);
	game._window.draw(_highscoreTitle);
}


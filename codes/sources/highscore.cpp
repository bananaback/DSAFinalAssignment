#include "../headers/highscore.h"

#include "../headers/game.h"

Highscore::Highscore(Game& game) {
	_highscoreBg.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SCORE_BG]);
	_highscoreBg.setScale(sf::Vector2f(12.f, 10.f));

	_highscoreTitle.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_highscoreTitle.setCharacterSize(100);
	_highscoreTitle.setFillColor(sf::Color::Black);
	_highscoreTitle.setPosition(sf::Vector2f(350, 10));
	_highscoreTitle.setString("TOP 10 BEST PLAYER");

	for (int i = 0; i < 10; i++) {
		_candidateList.push_back(std::make_shared<CandidateInfor>(game, 450, 150+70*i,
			"Tin cui bap " + std::to_string(i+1), 100*(i+1)));
	}
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
	for (size_t i = 0; i < _candidateList.size(); i++) {
		_candidateList[i]->update(game);
	}
}

void Highscore::render(Game& game) {
	game._window.draw(_highscoreBg);
	game._window.draw(_highscoreTitle);
	for (size_t i = 0; i < _candidateList.size(); i++) {
		_candidateList[i]->draw(game);
	}
}


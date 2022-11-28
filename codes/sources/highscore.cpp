#include <iostream>
#include <fstream>
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

	build(game);

	_char.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::IMG_FONT]);
	_char.setOrigin(10, 10);

	_name = "highscore";
}

Highscore::~Highscore() {

}

void Highscore::build(Game& game) {
	for (size_t i = 0; i < _candidateList.size(); i++) _candidateList[i] = nullptr;
	_candidateList.clear();
	std::ifstream MyReadFile("data/highscore.txt");
	std::string myText;
	int i = 0;
	while (std::getline(MyReadFile, myText)) {
		i++;
		std::cout << myText << "\n";
		size_t found = myText.find(";");
		std::string name, score;
		name = myText.substr(0, found);
		score = myText.substr(found + 1, myText.size() - 1);
		std::cout << name << " " << score << "\n";
		_candidateList.push_back(std::make_shared<CandidateInfor>(game, 200, 150 + 70 * (i - 1),
			name, std::stoi(score)));
	}
	MyReadFile.close();
	std::cout << i << "\n";
	for (; i < 10; i++) {
		_candidateList.push_back(std::make_shared<CandidateInfor>(game, 200, 150 + 70 * i,
			"BLANK", 0));
	}

}

void Highscore::handleEvents(Game& game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Enter) {
				game.changeState("mainmenu", 0, 0);
			}
		}
	}
}

void Highscore::update(Game& game) {
	for (size_t i = 0; i < _candidateList.size(); i++) {
		_candidateList[i]->update(game);
	}
}

void Highscore::drawText(Game& game, float x, float y, std::string s, float scale) {
	for (int i = 0; i < s.length(); i++) {
		_char.setTextureRect(game.ra_ptr->_imgFontIntRects[game.ra_ptr->_charMapping[s[i]]]);
		_char.setPosition(x+i*35, y);
		_char.setScale(sf::Vector2f(scale, scale));
		game._window.draw(_char);
	}
	
}

void Highscore::render(Game& game) {
	game._window.draw(_highscoreBg);
	game._window.draw(_highscoreTitle);
	for (size_t i = 0; i < _candidateList.size(); i++) {
		_candidateList[i]->draw(game);
		drawText(game, _candidateList[i]->getX(), _candidateList[i]->getY()+30, _candidateList[i]->getName(), 2);
		drawText(game, _candidateList[i]->getX()+700, _candidateList[i]->getY() + 30, "SCORE: " + std::to_string(_candidateList[i]->getScore()), 2);
	}
}


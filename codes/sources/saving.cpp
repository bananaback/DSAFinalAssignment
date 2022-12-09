#include <iostream>
#include <fstream>

#include "../headers/saving.h"
#include "../headers/game.h"

Saving::Saving(Game& game) {
	_savingBackground.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::SAVING_BG]);
	_savingBackground.setScale(sf::Vector2f(12.f, 10.f));

	_userName;
	_userName._x = 440;
	_userName._y = 300;
	_userName._width = 620;
	_userName._height = 60;
	_userName._focus = false;
	_userName._currentContext = "";
	_userName._text.setPosition(450, 270);
	_userName._text.setCharacterSize(80);
	_userName._text.setFillColor(sf::Color::Black);
	_userName._text.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);

	_savingText.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
	_savingText.setCharacterSize(100);
	_savingText.setFillColor(sf::Color::Black);
	_savingText.setPosition(350, 100);
	_savingText.setString("ENTER YOUR COOL NAME:");

	_tutorText.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
	_tutorText.setCharacterSize(100);
	_tutorText.setFillColor(sf::Color::Black);
	_tutorText.setPosition(350, 500);
	_tutorText.setString("CLICK ON THE TEXTBOX\n(A..Z, 0..9)\nNAME LENGTH <= 20\nPRESS ENTER TO SUBMIT");

	std::ifstream myScore("./data/score.txt");
	std::string currScore = "0";
	if (myScore.is_open()) {
		myScore >> currScore;
		_score = std::stoi(currScore);
	}
	else {
		std::cout << "Can't not read score.txt";
	}
	myScore.close();

	_scoreText.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
	_scoreText.setCharacterSize(100);
	_scoreText.setFillColor(sf::Color::Green);
	_scoreText.setPosition(450, 350);
	_scoreText.setString("YOUR SCORE: " + std::to_string(_score));

	_name = "saving";
}

Saving::~Saving() {

}

bool comp(std::pair<std::string, int> a, std::pair <std::string, int> b) {
	return a.second > b.second;
}

void Saving::handleEvents(Game& game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			std::string temp = "";
			if (pEvent.key.code == sf::Keyboard::A) {
				temp = "A";
			}
			if (pEvent.key.code == sf::Keyboard::B) {
				temp = "B";
			}
			if (pEvent.key.code == sf::Keyboard::C) {
				temp = "C";
			}
			if (pEvent.key.code == sf::Keyboard::D) {
				temp = "D";
			}
			if (pEvent.key.code == sf::Keyboard::E) {
				temp = "E";
			}
			if (pEvent.key.code == sf::Keyboard::F) {
				temp = "F";
			}
			if (pEvent.key.code == sf::Keyboard::G) {
				temp = "G";
			}
			if (pEvent.key.code == sf::Keyboard::H) {
				temp = "H";
			}
			if (pEvent.key.code == sf::Keyboard::I) {
				temp = "I";
			}
			if (pEvent.key.code == sf::Keyboard::J) {
				temp = "J";
			}
			if (pEvent.key.code == sf::Keyboard::K) {
				temp = "K";
			}
			if (pEvent.key.code == sf::Keyboard::L) {
				temp = "L";
			}
			if (pEvent.key.code == sf::Keyboard::M) {
				temp = "M";
			}
			if (pEvent.key.code == sf::Keyboard::N) {
				temp = "N";
			}
			if (pEvent.key.code == sf::Keyboard::O) {
				temp = "O";
			}
			if (pEvent.key.code == sf::Keyboard::P) {
				temp = "P";
			}
			if (pEvent.key.code == sf::Keyboard::Q) {
				temp = "Q";
			}
			if (pEvent.key.code == sf::Keyboard::R) {
				temp = "R";
			}
			if (pEvent.key.code == sf::Keyboard::S) {
				temp = "S";
			}
			if (pEvent.key.code == sf::Keyboard::T) {
				temp = "T";
			}
			if (pEvent.key.code == sf::Keyboard::U) {
				temp = "U";
			}
			if (pEvent.key.code == sf::Keyboard::V) {
				temp = "V";
			}
			if (pEvent.key.code == sf::Keyboard::W) {
				temp = "W";
			}
			if (pEvent.key.code == sf::Keyboard::X) {
				temp = "X";
			}
			if (pEvent.key.code == sf::Keyboard::Y) {
				temp = "Y";
			}
			if (pEvent.key.code == sf::Keyboard::Z) {
				temp = "Z";
			}
			if (pEvent.key.code == sf::Keyboard::Space) {
				temp = " ";
			}
			if (pEvent.key.code == sf::Keyboard::Num0) {
				temp = "0";
			}
			if (pEvent.key.code == sf::Keyboard::Num1) {
				temp = "1";
			}
			if (pEvent.key.code == sf::Keyboard::Num2) {
				temp = "2";
			}
			if (pEvent.key.code == sf::Keyboard::Num3) {
				temp = "3";
			}
			if (pEvent.key.code == sf::Keyboard::Num4) {
				temp = "4";
			}
			if (pEvent.key.code == sf::Keyboard::Num5) {
				temp = "5";
			}
			if (pEvent.key.code == sf::Keyboard::Num6) {
				temp = "6";
			}
			if (pEvent.key.code == sf::Keyboard::Num7) {
				temp = "7";
			}
			if (pEvent.key.code == sf::Keyboard::Num8) {
				temp = "8";
			}
			if (pEvent.key.code == sf::Keyboard::Num9) {
				temp = "9";
			}
			if (pEvent.key.code == sf::Keyboard::BackSpace) {
				if (_userName._focus) {
					if (_userName._currentContext.size() > 0) {
						_userName._currentContext.erase(_userName._currentContext.size() - 1);
					}
				}
			}
			if (_userName._focus) {
				if (_userName._currentContext.size() < 20) {
					_userName._currentContext += temp;
				}
			}
			if (pEvent.key.code == sf::Keyboard::Enter) {
				std::ifstream MyReadFile("data/highscore.txt");
				std::string myText;
				std::vector<std::pair<std::string, int>> playerList;
				while (std::getline(MyReadFile, myText)) {
					std::cout << myText << "\n";
					size_t found = myText.find(";");
					std::string name = "";
					std::string score = "";
					name = myText.substr(0, found);
					score = myText.substr(found + 1, myText.size() - 1);
					std::cout << name << " " << score << "\n";
					if (name.size() == 0) name = "NONAME";
					for (auto x : name) x = std::toupper(x);
					playerList.push_back(std::make_pair(name, std::stoi(score)));
				}
				MyReadFile.close();
				for (auto x : _userName._currentContext) x = std::toupper(x);
				if (_userName._currentContext.size() == 0) _userName._currentContext = "NONAME";
				playerList.push_back(std::make_pair(_userName._currentContext, _score));
				std::sort(playerList.begin(), playerList.end(), comp);
				int length = playerList.size();
				if (length > 10) length = 10;
				std::ofstream myOutFile("data/highscore.txt");
				for (int i = 0; i < length; i++) {
					myOutFile << playerList[i].first << ";" << playerList[i].second << "\n";
				}
				myOutFile.close();

				std::ofstream myWriteFile("./data/currentlevel.txt");
				if (myWriteFile.is_open()) {
					myWriteFile << 1;
				}
				else {
					std::cout << "Can't open currentlevel.txt to write";
				}
				myWriteFile.close();

				std::ofstream myScore("./data/score.txt");
				if (myScore.is_open()) {
					myScore << 0;
				}
				else
				{
					std::cout << "Can't open score.txt to write";
				}
				myScore.close();

				game.changeState("highscore", 0, 1);
			}
			
		}
		if (pEvent.type == sf::Event::MouseButtonReleased) {
			if (pEvent.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(game._window);
				if (mousePos.x >= _userName._x && mousePos.x <= _userName._x + _userName._width
					&& mousePos.y >= _userName._y && mousePos.y <= _userName._y + _userName._height) {
					_userName._focus = true;
				}
				else {
					_userName._focus = false;
				}
			}
		}
	}
}

void Saving::update(Game& game) {
	_userName._text.setString(_userName._currentContext);
}

void Saving::render(Game& game) {
	game._window.draw(_savingBackground);
	sf::RectangleShape rect;
	rect.setPosition(_userName._x, _userName._y);
	rect.setSize(sf::Vector2f(_userName._width, _userName._height));
	rect.setFillColor(sf::Color::White);
	rect.setOutlineThickness(2.f);
	rect.setOutlineColor(sf::Color::White);
	if (_userName._focus) rect.setOutlineColor(sf::Color::Blue);
	game._window.draw(rect);
	game._window.draw(_savingText);
	game._window.draw(_tutorText);
	game._window.draw(_scoreText);
	game._window.draw(_userName._text);
}
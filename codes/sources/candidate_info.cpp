#include "../headers/candidate_info.h"

CandidateInfo::CandidateInfo(Game& game, float x, float y, std::string name, int score) {
	_x = x;
	_y = y;
	_width = 620;
	_height = 60;
	_name = name;
	_score = score;
	
	_text.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::MONO]);
	_text.setCharacterSize(80);
	_text.setFillColor(sf::Color::Black);
	_text.setPosition(_x, _y-30);
	_text.setString(_name + " " + std::to_string(_score));
}

CandidateInfo::~CandidateInfo() {

}

void CandidateInfo::update(Game& game) {

}

float CandidateInfo::getX() {
	return _x;
}

float CandidateInfo::getY() {
	return _y;
}

std::string CandidateInfo::getName() {
	return _name;
}

int CandidateInfo::getScore() {
	return _score;
}

void CandidateInfo::draw(Game& game) {
	//sf::RectangleShape rect;
	//rect.setSize(sf::Vector2f(_width, _height));
	//rect.setFillColor(sf::Color::White);
	//rect.setPosition(sf::Vector2f(_x, _y));
	//game._window.draw(rect);
	//game._window.draw(_text);
}
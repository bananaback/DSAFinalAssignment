#include "../headers/mainmenu.h"
#include <iostream>
MainMenu::MainMenu() {
	_font.loadFromFile("assets/fonts/monogram-extended.ttf");

	_text.setFont(_font);
	_text.setPosition(280, 350);
	_text.setString("This is main menu!");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	_name = "mainmenu";
}

MainMenu::~MainMenu() {

};

void MainMenu::handleEvents(Game &game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			game.setRunning(false);
		}
	}
};
void MainMenu::update(Game &game) {

};
void MainMenu::render(Game &game) {
	/*sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(600, 50));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);
	game._window.draw(rectangle);*/
	game._window.draw(_text);
};
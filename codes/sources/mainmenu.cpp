#include "../headers/mainmenu.h"
#include <iostream>
// Constructor
MainMenu::MainMenu() {
	// load font
	_font.loadFromFile("assets/fonts/monogram-extended.ttf");

	// init text
	_text.setFont(_font);
	_text.setPosition(280, 350);
	_text.setString("This is main menu!");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	// Set state name to switch soon
	_name = "mainmenu";
}
// Destructor
MainMenu::~MainMenu() {

};
// Handle game events
void MainMenu::handleEvents(Game &game) {
	sf::Event pEvent;
	while (game._window.pollEvent(pEvent)) {
		if (pEvent.type == sf::Event::Closed) {
			// End game
			game.setRunning(false);
		}
		if (pEvent.type == sf::Event::KeyPressed) {
			if (pEvent.key.code == sf::Keyboard::Space) {
				game.changeState("gameplay");
			}
		}
	}
};
// Update game logic
void MainMenu::update(Game &game) {

};
// Render game
void MainMenu::render(Game &game) {
	/*sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(600, 50));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);
	game._window.draw(rectangle);*/
	// Draw the text
	game._window.draw(_text);
	/*sf::Sprite test;
	test.setTexture(*game.ra_ptr->_imageResources["player"]["1"]);
	game._window.draw(test);*/
	sf::Sprite mainMenuBg;
	mainMenuBg.setTexture(*game.ra_ptr->_imageResources["mainmenu"]["bg"]);
	mainMenuBg.setScale(sf::Vector2f(2.4f, 2.f));
	game._window.draw(mainMenuBg);

};
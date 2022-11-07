#include "../headers/mainmenu.h"
#include <iostream>
// Constructor
MainMenu::MainMenu() {
	// load font
	_font.loadFromFile("assets/fonts/monogram-extended.ttf");
	_font2.loadFromFile("assets/fonts/ThaleahFat.ttf");

	// init text
	_text.setFont(_font);
	_text.setPosition(280, 350);
	_text.setString("This is main menu!");
	_text.setCharacterSize(24);
	_text.setFillColor(sf::Color::White);
	_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	_gameTitle.setFont(_font2);
	_gameTitle.setPosition(500, 180);
	_gameTitle.setString("The shooting");
	_gameTitle.setCharacterSize(120);
	_gameTitle.setFillColor(sf::Color::Black);
	_gameTitle.setStyle(sf::Text::Bold);
	// Set state name to switch soon
	_name = "mainmenu";
	_btns.push_back(std::make_shared<Button>(700, 430, 100, 46, "play"));
	_btns.push_back(std::make_shared<Button>(700, 540, 100, 46, "setting"));
	_btns.push_back(std::make_shared<Button>(700, 650, 100, 46, "quit"));
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
	_mainMenuBg.setTexture(*game.ra_ptr->_imageResources["mainmenu"]["bg"]);
	_mainMenuBg.setScale(sf::Vector2f(2.4f, 2.f));
	game._window.draw(_mainMenuBg);
	//draw game title
	game._window.draw(_gameTitle);
	for (int i = 0; i < _btns.size(); i++)
	{
		_btns[i]->draw(game);
	}
};
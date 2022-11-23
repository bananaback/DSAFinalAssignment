#include "../headers/credit.h"
#include "../headers/game.h"

Credit::Credit(Game& game)
{
	_name = "credit";
	_background.setTexture(*game.ra_ptr->_imageResources[game.ra_ptr->IMAGE::CREDIT_BG]);
	_creditText.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::FONT_CREDIT]);
	_creditText.setString("CREDIT");
	_creditText.setFillColor(sf::Color::Black);
	_creditText.setScale(sf::Vector2f(5.f, 5.f));
	_creditText.setPosition(sf::Vector2f(540.f, 100.f));

	_person1.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_person1.setString("Member: Vo Trong Tin");
	_person1.setScale(sf::Vector2f(2.f, 2.f));
	_person1.setPosition(sf::Vector2f(400.f, 500.f));
	_person1.setFillColor(sf::Color::Black);

	_person2.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_person2.setString("Member: Cao Thi Thu Thuy");
	_person2.setScale(sf::Vector2f(2.f, 2.f));
	_person2.setPosition(sf::Vector2f(400.f, 600.f));
	_person2.setFillColor(sf::Color::Black);

	_person3.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_person3.setString("Member: Trinh Thi Thanh Huyen");
	_person3.setScale(sf::Vector2f(2.f, 2.f));
	_person3.setPosition(sf::Vector2f(400.f, 700.f));
	_person3.setFillColor(sf::Color::Black);

	_person4.setFont(*game.ra_ptr->_fontResources[game.ra_ptr->FONT::THALEAHFAT]);
	_person4.setString("Instructor: Nguyen Thuy An");
	_person4.setScale(sf::Vector2f(2.f, 2.f));
	_person4.setPosition(sf::Vector2f(400.f, 400.f));
	_person4.setFillColor(sf::Color::Black);

	_backMainMenu = std::make_shared<Button>(50, 50, 31, 28, "backmainmenu");
}

Credit::~Credit()
{
}

void Credit::handleEvents(Game& game)
{
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
	if (pEvent.type == sf::Event::MouseButtonReleased) {
		if (pEvent.mouseButton.button == sf::Mouse::Left) if (_backMainMenu->checkHover(game))game.changeState("mainmenu");
	}
}

void Credit::update(Game& game)
{
	_backMainMenu->update(game);
}

void Credit::render(Game& game)
{
	_background.setScale(sf::Vector2f(2.4f, 2.f));
	game._window.draw(_background);
	game._window.draw(_creditText);
	game._window.draw(_person1);
	game._window.draw(_person2);
	game._window.draw(_person3);
	game._window.draw(_person4);
	_backMainMenu->draw(game);
}

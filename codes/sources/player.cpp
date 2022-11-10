#include "../headers/player.h"
#include <iostream>
#include "../headers/grid.h"
Player::Player(float x, float y, float width, float height, Game& game, std::shared_ptr<Grid> pGrid) :Unit(x, y) {
	_x = x;
	_y = y;
	_nextX = x;
	_nextY = y;
	_width = width;
	_height = height;
	_name = "player";
	_currentAnimation = 0;
	_speed = 100;
	_parentGrid = pGrid;
	_scaleX = 3.f;
	_scaleY = 3.f;
	_assetWidth = 20;
	_assetHeight = 24;

	_monoFont.loadFromFile("assets/fonts/monogram-extended.ttf");
	_playerDebugMessage.setFont(_monoFont);
	_playerDebugMessage.setCharacterSize(24);
	_playerDebugMessage.setFillColor(sf::Color::White);

	float frameDuration = 0.1f;
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["e"], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "e"));//0
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["ne"], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "ne"));//1
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["se"], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "se"));//2
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["n"], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "n"));//3
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["s"], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "s"));//4
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["sgun"], 0, 0, _assetWidth, _assetHeight, 4, frameDuration, "sgun"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["idle"], 0, 0, _assetWidth, _assetHeight, 1, frameDuration, "idle"));
}

Player::~Player() {

}

void Player::update(Game& game) {
    bool updateAnim = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _nextY = _y - _speed * game._dt;
        updateAnim = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _nextY = _y + _speed * game._dt;
        updateAnim = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _nextX = _x - _speed * game._dt;
        updateAnim = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _nextX = _x + _speed * game._dt;
        updateAnim = true;
    }
	std::shared_ptr<Unit> thisUnit = shared_from_this();
	_parentGrid->move(thisUnit, thisUnit->getNextX(), thisUnit->getNextY());
	_x = _nextX;
	_y = _nextY;
    if (updateAnim) _animations[_currentAnimation]->update(game._dt);
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(game._window);
    float angle = std::atan2(-(mouse_pos.y - (_y + _width / 2)), -(mouse_pos.x - (_x + _height / 2))) * 180 / (std::atan(1) * 4);
	int a = std::floor((angle + 180 + 22.5) / 45);
	_currentAnimation = _assetName[a];
	if (std::abs(angle) < 67.5) _scaleX = -3.f; else _scaleX = 3.f;

	_playerDebugMessage.setPosition(_x, _y - 20);
	_playerDebugMessage.setString(std::to_string(a));
}

void Player::draw(Game& game) {
	_animations[_currentAnimation]->_sprite.setPosition(_x + _width / 2, _y + _height / 2);
	_animations[_currentAnimation]->_sprite.setOrigin(_assetWidth/2, _assetHeight/2);
	_animations[_currentAnimation]->_sprite.setScale(_scaleX, _scaleY);
	game._window.draw(_animations[_currentAnimation]->_sprite);


	/*sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setPosition(_x, _y);
	rectangle.setFillColor(sf::Color(255, 255, 255, 100));
	game._window.draw(rectangle);
	*/
	game._window.draw(_playerDebugMessage);
}

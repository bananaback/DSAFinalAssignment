#include "../headers/player.h"
#include <iostream>
Player::Player(float x, float y, float width, float height, Game& game) :Unit(x, y) {
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_name = "player";
	_scaleX = 1;
	_scaleY = 1;
	_currentAnimation = 0;

	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["1"], 0, 0, 16, 21, 1, (float)0.1, "idle"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["1_diagdown"], 0, 0, 20, 24, 4, (float)0.1, "1_diagdown"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["1_diagup"], 0, 0, 20, 24, 4, (float)0.1, "1_diagup"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["1_north"], 0, 0, 20, 24, 4, (float)0.1, "1_north"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["1_side"], 0, 0, 20, 24, 4, (float)0.1, "1_side"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["1_south"], 0, 0, 20, 24, 4, (float)0.1, "1_south"));
	_animations.push_back(std::make_shared<Animation>(game.ra_ptr->_imageResources["player"]["1_south2"], 0, 0, 20, 24, 4, (float)0.1, "1_south2"));
}

Player::~Player() {

}

void Player::update(Game& game) {
    bool updateAnim = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        _y -= 100 * game._dt;
        updateAnim = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        _y += 100 * game._dt;
        updateAnim = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        _x -= 100 * game._dt;
        updateAnim = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        _x += 100 * game._dt;
        updateAnim = true;
    }


    if (updateAnim) _animations[_currentAnimation]->update(game._dt);
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(game._window);
    float angle = std::atan2(-(mouse_pos.y - (_y + _width / 2)), -(mouse_pos.x - (_x + _height / 2))) * 180 / (std::atan(1) * 4);
    if (angle >= 0) {
        if (angle <= 22.5) {
            _currentAnimation = 4;
            _scaleX = -1;
        }
        else if (angle <= 22.5 + 45) {
            _currentAnimation = 2;
            _scaleX = -1;
        }
        else if (angle <= 90 + 22.5) {
            _currentAnimation = 3;
        }
        else if (angle <= 135 + 22.5) {
            _currentAnimation = 2;
            _scaleX = 1;
        }
        else {
            _currentAnimation = 4;
            _scaleX = 1;
        }
    }
    else if (angle < 0) {
        if (angle >= -22.5) {
            _currentAnimation = 4;
            _scaleX = -1;
        }
        else if (angle >= -67.5) {
            _currentAnimation = 1;
            _scaleX = -1;
        }
        else if (angle >= -112.5) {
            _currentAnimation = 5;
        }
        else if (angle >= -157.5) {
            _currentAnimation = 1;
            _scaleX = 1;
        }
        else {
            _currentAnimation = 4;
            _scaleX = 1;
        }
    }
    //std::cout << game._dt << "\n";
}

void Player::draw(Game& game) {
	_animations[_currentAnimation]->_sprite.setPosition(_x + _width / 2, _y + _height / 2);
	_animations[_currentAnimation]->_sprite.setOrigin(10, 12);
	_animations[_currentAnimation]->_sprite.setScale(3.f * _scaleX, 3.f * _scaleY);
	game._window.draw(_animations[_currentAnimation]->_sprite);


	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(_width, _height));
	rectangle.setPosition(_x, _y);
	rectangle.setFillColor(sf::Color(255, 255, 255, 100));
}

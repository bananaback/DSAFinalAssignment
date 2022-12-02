#include <iostream>
#include "../headers/weapon.h"

Weapon::Weapon(Game& game) {
	_x = 0;
	_y = 0;
	_width = 0;
	_height = 0;
	_scale = 0;
	_currentDir = 0;
	_centerX = 0;
	_centerY = 0;
	//  => 2 3 4 3 2 1 0 1 2 
	dirMap.push_back(2);
	dirMap.push_back(3);
	dirMap.push_back(4);
	dirMap.push_back(3);
	dirMap.push_back(2);
	dirMap.push_back(1);
	dirMap.push_back(0);
	dirMap.push_back(1);
	dirMap.push_back(2);
	// scaleMap
	scaleXMap.push_back(1);
	scaleXMap.push_back(1);
	scaleXMap.push_back(1);
	scaleXMap.push_back(-1);
	scaleXMap.push_back(-1);
	scaleXMap.push_back(-1);
	scaleXMap.push_back(-1);
	scaleXMap.push_back(1);
	scaleXMap.push_back(1);
	// angleMap 0
	angleMap.push_back(180.f / 180.f * (std::atan(1) * 4)); //0
	angleMap.push_back(-45.f / 180.f * (std::atan(1) * 4)); //1
	angleMap.push_back(-90.f / 180.f * (std::atan(1) * 4)); //2
	angleMap.push_back(-135.f / 180.f * (std::atan(1) * 4)); //3
	angleMap.push_back(0.f / 180.f * (std::atan(1) * 4)); //4
	angleMap.push_back(45.f / 180.f * (std::atan(1) * 4)); //5
	angleMap.push_back(90.f / 180.f * (std::atan(1) * 4)); //6
	angleMap.push_back(135.f / 180.f * (std::atan(1) * 4)); //7
	angleMap.push_back(180.f / 180.f * (std::atan(1) * 4)); //8
}

Weapon::~Weapon() {

}

int Weapon::determineDirFromAngle(float angle) {
	int a = std::floor((angle + 180 + 22.5) / 45);
	return a;
}

void Weapon::updateWeapon(Game& game, float angle, float playerCenterX, float playerCenterY) {
	_currentDir = determineDirFromAngle(angle);
	_sprite.setTexture(*_textureSet[dirMap[_currentDir]]);
	_x = playerCenterX + std::cos((angle+180)/180*(std::atan(1)*4)) * _radius;
	_y = playerCenterY + std::sin((angle+180)/180*(std::atan(1)*4)) * _radius;
	_width = _textureSize[_currentDir].first * _scale;
	_height = _textureSize[_currentDir].second * _scale;
	_width = _sprite.getTexture()->getSize().x;
	_height = _sprite.getTexture()->getSize().y;
	_sprite.setOrigin(_textureSize[_currentDir].first / 2, _textureSize[_currentDir].second / 2);
	_sprite.setTextureRect(sf::IntRect(0, 0, _textureSize[_currentDir].first, _textureSize[_currentDir].second));
	_sprite.setPosition(sf::Vector2f(_x, _y));
	_sprite.setScale(scaleXMap[_currentDir]*_scale, _scale);
	_centerX = _x + _width / 2;
	_centerY = _y + _height / 2;
}

void Weapon::drawWeapon(Game& game) {
	game._window.draw(_sprite);
}
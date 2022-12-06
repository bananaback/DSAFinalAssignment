#include "../headers/character.h"
#include "../headers/calculator.h"
Character::Character(float x, float y, float width, float height) : GameObject(x, y, width, height) {
	canGoUp = true;
	canGoDown = true;
	canGoLeft = true;
	canGoRight = true;
}

Character::~Character() {

}

void Character::resolveCollisionWithWall(Wall& wall, int offset) {
	int otherX = wall.getX();
	int otherY = wall.getY();
	int otherW = wall.getWidth();
	int otherH = wall.getHeight();
	canGoUp = canGoUp && !checkCollisionBetweenTwoRect(
		_x, _y - offset, _width, offset,
		otherX, otherY, otherW, otherH);

	canGoDown = canGoDown && !checkCollisionBetweenTwoRect(
		_x, _y + _height, _width, offset,
		otherX, otherY, otherW, otherH);

	canGoLeft = canGoLeft && !checkCollisionBetweenTwoRect(
		_x - offset, _y, offset, _height,
		otherX, otherY, otherW, otherH);

	canGoRight = canGoRight && !checkCollisionBetweenTwoRect(
		_x + _width, _y, offset, _height,
		otherX, otherY, otherW, otherH);
}

void Character::resolveCollisionWithSpawner(Spawner& spawner, int offset) {
	int otherX = spawner.getX();
	int otherY = spawner.getY();
	int otherW = spawner.getWidth();
	int otherH = spawner.getHeight();
	canGoUp = canGoUp && !checkCollisionBetweenTwoRect(
		_x, _y - offset, _width, offset,
		otherX, otherY, otherW, otherH);

	canGoDown = canGoDown && !checkCollisionBetweenTwoRect(
		_x, _y + _height, _width, offset,
		otherX, otherY, otherW, otherH);

	canGoLeft = canGoLeft && !checkCollisionBetweenTwoRect(
		_x - offset, _y, offset, _height,
		otherX, otherY, otherW, otherH);

	canGoRight = canGoRight && !checkCollisionBetweenTwoRect(
		_x + _width, _y, offset, _height,
		otherX, otherY, otherW, otherH);
}

void Character::resetMove() {
	canGoUp = true;
	canGoDown = true;
	canGoLeft = true;
	canGoRight = true;
}

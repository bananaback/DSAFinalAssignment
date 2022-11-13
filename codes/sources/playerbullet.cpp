#include "../headers/playerbullet.h"
#include "../headers/bullet.h"
#include <iostream>
PlayerBullet::PlayerBullet(float x, float y, float width, float height, float speed, float damage) : Bullet(x, y, width, height, speed, damage) {
	
}

PlayerBullet::~PlayerBullet(){
	std::cout << "Player bullet destroyed\n";
}

void PlayerBullet::update(Game& game) {

}

void PlayerBullet::draw(Game& game) {

}

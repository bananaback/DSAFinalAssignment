#include "../headers/animation.h"
#include <iostream>
Animation::Animation() {
	_frame = 0;
	_frameTime = 0;
	_timer = 0;
	_name = "";
	_finishOnce = false;
}

Animation::Animation(std::shared_ptr<sf::Texture> t, int x, int y, int w, int h, int count, float frameTime, std::string name) {
	_frame = 0;
	_timer = 0;
	_frameTime = frameTime;
	_name = name;
	for (int i = 0; i < count; i++) {
		_frames.push_back(sf::IntRect(x + i * w, y, w, h));
	}
	_sprite.setTexture(*t);
	_sprite.setOrigin(1.f * w / 2, 1.f * h / 2);
	_sprite.setTextureRect(_frames[0]);
	_w = w;
	_h = h;
	_finishOnce = false;
}

void Animation::update(float& dt) {
	_timer += dt;
	if (_timer > _frameTime) {
		_timer = 0;
		_frame++;
	}
	int n = _frames.size();
	if (_frame >= n) {
		_frame = 0;
		_finishOnce = true;
	}
	if (n > 0) _sprite.setTextureRect(_frames[int(_frame)]);
}

void Animation::draw(Game& game, float x, float y, float rot, float scaleX, float scaleY, float originX, float originY) {
	_sprite.setPosition(x, y);
	_sprite.setOrigin(originX, originY);
	_sprite.setScale(scaleX, scaleY);
	game._window.draw(_sprite);
}

bool Animation::isEnd() {
	return _frame >= _frames.size();
}



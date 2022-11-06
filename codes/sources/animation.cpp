#include "../headers/animation.h"

Animation::Animation() {
	_frame = 0;
	_frameTime = 0;
	_timer = 0;
	_name = "";
}

Animation::Animation(std::shared_ptr<sf::Texture> t, int x, int y, int w, int h, int count, float frameTime, std::string name) {
	_frame = 0;
	_timer = 0;
	this->_frameTime = _frameTime;
	this->_name = _name;
	for (int i = 0; i < count; i++) {
		_frames.push_back(sf::IntRect(x + i * w, y, w, h));
	}
	_sprite.setTexture(*t);
	_sprite.setOrigin(1.f * w / 2, 1.f * h / 2);
	_sprite.setTextureRect(_frames[0]);
}

void Animation::update(float& dt) {
	_timer += dt;
	if (_timer > _frameTime) {
		_timer = 0;
		_frame++;
	}
	int n = _frames.size();
	if (_frame >= n) _frame = 0;
	if (n > 0) _sprite.setTextureRect(_frames[int(_frame)]);
}

bool Animation::isEnd() {
	return _frame >= _frames.size();
}



#include <cmath>
#include "../headers/calculator.h"

float calculateAngle(float x, float y, float x2, float y2) {
	return std::atan2(y2 - y, x2 - x);
}

float distance(float x, float y, float x2, float y2) {
	float dx = x2 - x;
	float dy = y2 - y;
	return std::sqrt(dx * dx + dy * dy);
}

bool checkCollisionBetweenTwoRect(float l, float t, float w, float h, float l2, float t2, float w2, float h2) {
	if (l > l2 + w2 || l2 > l + w) return false;
	if (t > t2 + h2 || t2 > t + h) return false;
	return true;
}

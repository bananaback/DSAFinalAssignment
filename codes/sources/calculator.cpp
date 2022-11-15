#include "../headers/calculator.h"
#include <cmath>
float angleCalc(float x, float y, float x2, float y2) {
	return std::atan2(y2 - y, x2 - x);
}

bool AABBVsAABB(float l, float t, float r, float b, float l2, float t2, float r2, float b2) {
	if (l > r2 || l2 > r) return false;
	if (t > b2 || t2 > b) return false;
	return true;
}
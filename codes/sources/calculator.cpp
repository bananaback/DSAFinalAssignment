#include "../headers/calculator.h"
#include <cmath>
float calculateAngle(float x, float y, float x2, float y2) {
	return std::atan2(y2 - y, x2 - x);
}
#pragma once
#ifndef  CALCULATOR_H
#define CALCULATOR_H

#include <cmath>

const float PI = std::acos(-1);
const float HALF_PI = std::acos(0);

float calculateAngle(float x, float y, float x2, float y2);
float distance(float x, float y, float x2, float y2);
bool checkCollisionBetweenTwoRect(float l, float t, float w, float h, float l2, float t2, float w2, float h2);
float deg2rad(float deg);
float rad2deg(float rad);


#endif // ! CALCULATOR_H

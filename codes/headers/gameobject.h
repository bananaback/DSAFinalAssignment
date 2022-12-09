#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
public:
	GameObject(float x, float y, float width, float height);
	~GameObject();
	bool isDestroyed();
	void destroy();
	float getX(), getY(), getWidth(), getHeight();
	bool checkCollision(GameObject& other);
	void limitObjectToScreen();
protected:
	float _x, _y, _width, _height;
	bool _isDestroyed;
};

#endif // !GAMEOBJECT_H


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
	int getCollisionStatus(GameObject& other, int offset);
	static const int COLLISION_LEFT = 1 << 0;
	static const int COLLISION_RIGHT = 1 << 1;
	static const int COLLISION_UP = 1 << 2;
	static const int COLLISION_DOWN = 1 << 3;
protected:
	float _x, _y, _width, _height;
	bool _isDestroyed;
	
};

#endif // !GAMEOBJECT_H


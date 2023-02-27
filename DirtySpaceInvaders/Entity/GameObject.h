#pragma once
#include "../Vector.h"

class PlayField;

class GameObject
{
public:
	char* m_objType = nullptr;
	Vector2D pos;
	unsigned char sprite;

	virtual void Update(PlayField& world) {};
	bool DecreaseHealth() { return true; };
};
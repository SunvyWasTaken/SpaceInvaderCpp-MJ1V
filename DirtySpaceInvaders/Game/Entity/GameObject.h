#pragma once
#include "Game/Engine/Vector.h"

class PlayField;

class GameObject
{
public:
	~GameObject();
	char* m_objType = nullptr;
	Vector2D pos;
	unsigned char sprite = '\0';

	bool IsType(const char* type);
	virtual void Update(PlayField& world) = 0;
	virtual bool DecreaseHealth() { return true; };
};
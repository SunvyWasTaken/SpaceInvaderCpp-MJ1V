#pragma once
#include "Game/Engine/Vector.h"
#include <string>

class PlayField;

class GameObject
{
public:
	~GameObject();
	std::string m_objType;
	Vector2D pos;
	enum ERaiderSprites sprite;

	bool IsType(const char* type);
	virtual void Update(PlayField& world) = 0;
	virtual bool DecreaseHealth() { return true; };
};
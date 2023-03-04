#pragma once
#include "Game/Engine/Vector.h"

class PlayField;

class GameObject
{

friend class UActorFactory;

protected:

	GameObject();

public:
	~GameObject();
	char* m_objType = nullptr;
	Vector2D pos;
	unsigned char sprite = '\0';

	/// <summary>
	/// Fonction call lorsque l'objet spawn;
	/// </summary>
	virtual void BeginPlay();

	virtual void Update(PlayField& world) = 0;
	bool DecreaseHealth() { return true; };
};
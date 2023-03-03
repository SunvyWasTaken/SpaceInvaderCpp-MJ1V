#pragma once
#include "GameObject.h"

class PlayerShip : public GameObject
{
public:
	PlayerShip();

	void Update(PlayField& world);
};
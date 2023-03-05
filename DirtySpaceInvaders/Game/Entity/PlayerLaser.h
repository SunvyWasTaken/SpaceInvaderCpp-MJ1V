#pragma once
#include "GameObject.h"

class PlayerLaser : public GameObject
{
public:
	PlayerLaser();

	void Update(PlayField& world);
};
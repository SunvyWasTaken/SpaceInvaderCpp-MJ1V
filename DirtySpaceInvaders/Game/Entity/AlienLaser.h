#pragma once
#include "GameObject.h"

class AlienLaser : public GameObject
{
public:
	AlienLaser();

	void Update(PlayField& world);
};
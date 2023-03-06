#pragma once
#include "GameObject.h"

class PlayerShip : public GameObject
{
public:
	PlayerShip();

	void Update(PlayField& world);

	unsigned Health;

	bool DecreaseHealth() override;
};
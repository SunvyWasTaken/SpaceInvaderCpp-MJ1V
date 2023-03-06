#pragma once
#include "GameObject.h"

class PlayerShip : public GameObject
{
public:
	PlayerShip();

	void Update(PlayField& world);

	bool DecreaseHealth() override;

private:

	unsigned Health;
};
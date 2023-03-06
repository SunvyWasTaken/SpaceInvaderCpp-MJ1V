#pragma once
#include "GameObject.h"

class Alien : public GameObject
{
public:
	Alien();

private:
	float health;
	float energy;
	float direction;
	float velocity;

	bool DecreaseHealth() { health -= 1.f; return health <= 0; }

	void Update(PlayField& world);
};
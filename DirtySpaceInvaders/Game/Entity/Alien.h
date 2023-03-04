#pragma once
#include "GameObject.h"

class Alien : public GameObject
{
friend class UActorFactory;
private:

	Alien();

private:
	float health = 1.f;
	float energy = 0.f;
	float direction = 1.f;
	float velocity = 0.5f;

	bool DecreaseHealth() { health -= 1.f; return health <= 0; }

	void Update(PlayField& world);
};
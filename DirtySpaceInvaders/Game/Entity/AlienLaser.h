#pragma once
#include "GameObject.h"

class AlienLaser : public GameObject
{
public:
	AlienLaser();

	void BeginPlay() override;

	void Update(PlayField& world);
};
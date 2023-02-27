#pragma once
#include "GameObject.h"

class AlienLaser : public GameObject
{
public:
	AlienLaser();
	~AlienLaser() { delete[] m_objType; }

	void Update(PlayField& world);
};
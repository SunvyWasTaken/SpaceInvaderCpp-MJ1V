#include "Alien.h"
#include "Game/Engine/PlayField.h"
#include "AlienLaser.h"
#include "Game/Render/ConsoleRenderer.h"

#include <random>
#include <string>

typedef std::uniform_real_distribution<float> floatRand;

Alien::Alien() 
{
	m_objType = new char[64];
	strcpy(m_objType, "AlienShip");
	sprite = RS_Alien;
}

void Alien::Update(PlayField& world)
{
	pos.x += direction * velocity;
	// Border check
	if (pos.x < 0 || pos.x >= world.bounds.x - 1)
	{
		direction = -direction;
		pos.y += 1;
	}

	// Border check vertical:
	if (pos.y >= world.bounds.y - 1)
	{
		// kill player
		GameObject* player = world.GetPlayerObject();
		if (pos.IntCmp(player->pos))
		{
			world.RemoveObject(player);
		}
	}

	floatRand fireRate(0, 1);
	if (fireRate(*GetrGen()) < 0.5 && world.AlienLasers > 0)
	{
		//Spawn laser
		GameObject* newLaser = new AlienLaser();
		newLaser->pos = pos;
		world.SpawnLaser(newLaser);
	}
}

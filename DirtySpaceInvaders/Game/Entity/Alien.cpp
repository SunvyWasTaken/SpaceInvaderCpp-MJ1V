#include "Alien.h"
#include "Game/Engine/PlayField.h"
#include "AlienLaser.h"
#include "Game/Render/ConsoleRenderer.h"

#include <random>
#include <string>

typedef std::uniform_real_distribution<float> floatRand;

Alien::Alien()
{
#include "Game/GameStat.h"
	health = AALIENHEALTH;
	energy = AALIENENERGY;
	direction = AALIENDIRECTION;
	velocity = AALIENVELOCITY;
#include "Game/UndefAllStat.h"

	m_objType = "AlienShip";
	sprite = RS_Alien;
}


void Alien::Update(PlayField& world)
{
	pos.x += direction * velocity;
	// Border check
	if (pos.x < 0 || pos.x >= world.bounds.x - 1)
	{
		CollideForward();
	}

	// Border check vertical:
	if (pos.y >= world.bounds.y - 1 || pos.y < 0)
	{
		world.RemoveObject(this);
		return;
	}

	std::vector<GameObject*> Lists = world.GameObjects();
	for (auto curEnti : Lists)
	{
		if (curEnti->IsType("Rock"))
		{
			if (pos.IntCmp(curEnti->pos))
			{
				CollideForward();
			}
		}
	}

	// kill player
	GameObject* player = world.GetPlayerObject();
	if (pos.IntCmp(player->pos))
	{
		world.RemoveObject(player);
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

void Alien::CollideForward()
{
	direction *= -1;
	pos.y += 1;
}

#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "Game/Engine/PlayField.h"
#include "Game/Render/ConsoleRenderer.h"
#include "Game/GameStat.h"

#include <string>

PlayerShip::PlayerShip() : Health(PLAYERHEALTH)
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerShip");
	sprite = RS_Player;
}

#include "Game/UndefAllStat.h"

void PlayerShip::Update(PlayField& world)
{
	if (world.GetInputController()->Left())
	{
		if (pos.x - 1 > 0)
		{
			pos.x -= 1;
		}
	}
	else if (world.GetInputController()->Right())
	{
		if (pos.x + 1 < world.bounds.x)
		{
			pos.x += 1;
		}
	}

	if (world.GetInputController()->Fire() && world.PlayerLasers > 0)
	{
		//Spawn laser
		GameObject* newLaser = new PlayerLaser();
		newLaser->pos = pos;
		world.SpawnLaser(newLaser);
	}
}

bool PlayerShip::DecreaseHealth()
{
	Health -= 1;
	return Health <= 0;
}
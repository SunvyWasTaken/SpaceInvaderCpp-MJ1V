#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "Game/Engine/PlayField.h"
#include "Game/Render/ConsoleRenderer.h"
#pragma warning(disable : 4996)

#include <string>

PlayerShip::PlayerShip()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerShip");
	sprite = RS_Player;
}

void PlayerShip::Update(PlayField& world)
{
	if (world.GetInputController()->Left())
		pos.x -= 1;
	else if (world.GetInputController()->Right())
		pos.x += 1;

	if (world.GetInputController()->Fire() && world.PlayerLasers > 0)
	{
		//Spawn laser
		GameObject* newLaser = new PlayerLaser();
		newLaser->pos = pos;
		world.SpawnLaser(newLaser);
	}
}

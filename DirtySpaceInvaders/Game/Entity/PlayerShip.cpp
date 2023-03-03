#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "PlayField.h"
#include "../ConsoleRenderer.h"

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

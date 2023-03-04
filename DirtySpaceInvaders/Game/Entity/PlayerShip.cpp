#include "PlayerShip.h"
#include "PlayerLaser.h"
#include "Game/Engine/PlayField.h"
#include "Game/Render/ConsoleRenderer.h"

#include <string>

PlayerShip::PlayerShip()
{
	m_objType = new char[64];
	strcpy_s(m_objType, sizeof(m_objType), "PlayerShip");
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
		GameObject* newLaser = UActorFactory::GetFactory()->CreateActor<PlayerLaser>();
		newLaser->pos = pos;
		world.SpawnLaser(newLaser);
	}
}

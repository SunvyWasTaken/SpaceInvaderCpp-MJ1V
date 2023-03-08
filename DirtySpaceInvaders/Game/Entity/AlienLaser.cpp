#include "AlienLaser.h"
#include "Game/Engine/PlayField.h"
#include "Game/Render/ConsoleRenderer.h"

#include <string>

AlienLaser::AlienLaser()
{
	m_objType = "AlienLaser";
	sprite = RS_AlienLaser;
}

void AlienLaser::Update(PlayField& world)
{
	bool deleted = false;
	pos.y += 1.f;
	if (pos.y > world.bounds.y)
	{
		deleted = true;
	}

	GameObject* player = world.GetPlayerObject();
	if (player)
	{
		if (pos.IntCmp(player->pos))
		{
			deleted = true;
			if (player->DecreaseHealth())
			{
				world.RemoveObject(player);
			}
		}
	}
	for (const auto& Object : world.GameObjects())
	{
		if (Object->IsType("Rock"))
		{
			if (pos.IntCmp(Object->pos))
			{
				deleted = true;
				break;
			}
		}
	}
	if (deleted)
	{
		world.DespawnLaser(this);
	}
}
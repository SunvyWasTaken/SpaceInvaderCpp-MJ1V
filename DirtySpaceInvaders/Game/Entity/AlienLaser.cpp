#include "AlienLaser.h"
#include "Game/Engine/PlayField.h"
#include "Game/Render/ConsoleRenderer.h"
#pragma warning(disable : 4996)

#include <string>

AlienLaser::AlienLaser()
{
	m_objType = new char[64];
	strcpy(m_objType, "AlienLaser");
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
	if (pos.IntCmp(player->pos))
	{
		deleted = true;
		world.RemoveObject(player);
	}

	if (deleted)
	{
		world.DespawnLaser(this);
	}
}
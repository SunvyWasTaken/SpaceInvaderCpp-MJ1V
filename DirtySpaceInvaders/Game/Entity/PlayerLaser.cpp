#include "PlayerLaser.h"
#include "Game/Engine/PlayField.h"
#include "Game/Render/ConsoleRenderer.h"
#pragma warning(disable : 4996)

#include <string>

PlayerLaser::PlayerLaser()
{
	m_objType = new char[64];
	strcpy(m_objType, "PlayerLaser");
	sprite = RS_PlayerLaser;
}

void PlayerLaser::Update(PlayField& world)
{
	bool deleted = false;
	pos.y -= 1.f;
	const std::vector<GameObject*>& OtherObjects = world.GameObjects();
	for (const auto& CurrentObject : OtherObjects)
	{
		if (!&CurrentObject)
		{
			continue;
		}
		if (strcmp(CurrentObject->m_objType, "AlienShip") == 0)
		{
			if (pos.IntCmp(CurrentObject->pos))
			{
				deleted = true;
				world.RemoveObject(CurrentObject);
				break;
			}
		}
		else if (strcmp(CurrentObject->m_objType, "Rock") == 0)
		{
			if (pos.IntCmp(CurrentObject->pos))
			{
				deleted = true;
			}
		}
	}
	if (pos.y < 0)
	{
		deleted = true;
	}

	if (deleted)
	{
		world.DespawnLaser(this);
	}

}
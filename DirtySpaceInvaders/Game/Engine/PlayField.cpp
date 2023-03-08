#include "PlayField.h"
#include "Game/Engine/Vector.h"
#include "Game/Entity/GameObject.h"

PlayField::PlayField(Vector2D iBounds) : bounds(iBounds), controllerInput(nullptr)
{
#include "Game/GameStat.h"
	AlienLasers = NBRALIENLASER;
	PlayerLasers = NBRPLAYERLASER;
#include "Game/UndefAllStat.h"

}

void PlayField::Update()
{
	for (auto i : ObjectToAdd)
	{
		gameObjects.push_back(i);
	}
	ObjectToAdd.clear();
	// Update list of active objects in the world
	for (auto* CurrentObject : gameObjects)
	{
		CurrentObject->Update(*this);
	}
	if (!ObjectsToDestroy.empty())
	{
		for (auto i : ObjectsToDestroy)
		{
			auto it = std::find(gameObjects.begin(), gameObjects.end(), i);
			delete *it;
			gameObjects.erase(it);
		}
		ObjectsToDestroy.clear();
	}
}

GameObject* PlayField::GetPlayerObject()
{
	auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](GameObject* in) { return (strcmp(in->m_objType, "PlayerShip") == 0); });
	if (it != gameObjects.end())
		return (*it);
	else
		return nullptr;
}

void PlayField::SetController(Input* InputRef)
{
	if (!InputRef)
		return;
	controllerInput = InputRef;
}

void PlayField::SpawnLaser(GameObject* newObj)
{
	if (newObj->IsType("AlienLaser"))
		AlienLasers--;

	else if (newObj->IsType("PlayerLaser"))
		PlayerLasers--;

	AddObject(newObj);
}

void PlayField::DespawnLaser(GameObject* newObj)
{
	if (newObj->IsType("AlienLaser"))
		AlienLasers++;

	else if (newObj->IsType("PlayerLaser"))
		PlayerLasers++;

	RemoveObject(newObj);
}

void PlayField::AddObject(GameObject* newObj)
{
	ObjectToAdd.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
	// Check si le player meur. SALE
	if (newObj->IsType("PlayerShip"))
	{
		exit(0);
	}
	auto it = std::find(ObjectsToDestroy.begin(), ObjectsToDestroy.end(), newObj);
	if (it != ObjectsToDestroy.end())
	{
		return;
	}
	ObjectsToDestroy.push_back(newObj);
}

#include "PlayField.h"
#include "Game/Engine/Vector.h"
#include "Game/Entity/GameObject.h"

PlayField::PlayField(Vector2D iBounds) : bounds(iBounds), controllerInput(nullptr)
{}

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

const std::vector<GameObject*>& PlayField::GetAllOtherObject() const
{
	std::vector<GameObject*> NonePlayer = gameObjects;
	auto it = std::find_if(NonePlayer.begin(), NonePlayer.end(), [](GameObject* in) { return (strcmp(in->m_objType, "PlayerShip") == 0); });
	if (it != NonePlayer.end()) {
		NonePlayer.erase(it);
	}
	return NonePlayer;
}

void PlayField::SetController(Input* InputRef)
{
	if (!InputRef)
		return;
	controllerInput = InputRef;
}

void PlayField::SpawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		AlienLasers--;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		PlayerLasers--;

	AddObject(newObj);
}

void PlayField::DespawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		AlienLasers++;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		PlayerLasers++;

	RemoveObject(newObj);
}

void PlayField::AddObject(GameObject* newObj)
{
	ObjectToAdd.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
	auto it = std::find(ObjectsToDestroy.begin(), ObjectsToDestroy.end(), newObj);
	if (it != ObjectsToDestroy.end())
	{
		return;
	}
	ObjectsToDestroy.push_back(newObj);
}

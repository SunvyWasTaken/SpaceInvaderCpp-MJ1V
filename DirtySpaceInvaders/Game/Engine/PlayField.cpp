#include "PlayField.h"
#include "Game/Engine/Vector.h"
#include "Game/Entity/GameObject.h"
#include "Game/GameStat.h"
#include "Game/Entity/AlienStonk.h"
#include "Game/Entity/Rock.h"
#include "Game/Entity/PlayerShip.h"

#include <thread>
#include <functional>

PlayField::PlayField(Vector2D iBounds) : bounds(iBounds), controllerInput(nullptr)
{
	AlienLasers = NBRALIENLASER;
	PlayerLasers = NBRPLAYERLASER;

	xCoord = intRand(0, (int)iBounds.x - 1);
	yCoord = intRand(0, (int)iBounds.y / 2);
}

void PlayField::Init()
{
	std::thread t1(&PlayField::SpawnAlien<Alien>, GetWorld());

	SpawnRock();
	SpawnPlayer();
	controllerInput = new PlayerInput();
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
	if (!IsShipLeft("AlienShip"))
	{
		std::thread t1(&PlayField::SpawnAlien<Alien>, GetWorld());
	}

	// Sleep a bit so updates don't run too fast
	std::this_thread::sleep_for(std::chrono::milliseconds(30));
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

bool PlayField::IsShipLeft(const char* _Name)
{
	for (const auto CurrentObject : gameObjects)
	{
		if (CurrentObject->IsType(_Name))
		{
			return true;
		}
	}
	return false;
}

void PlayField::SpawnPlayer()
{
	PlayerShip* p = new PlayerShip();
	Vector2D PlayerSpawn = PLAYERSPAWN;
	p->pos = PlayerSpawn;
	GetWorld()->AddObject(p);
}

void PlayField::SpawnRock()
{
	// ajour des roches
	for (int i = 0; i < NBRROCK; i++)
	{
		ARock* r = new ARock();
		r->pos.x = (float)xCoord(*GetrGen());
		r->pos.y = (float)yCoord(*GetrGen());
		GetWorld()->AddObject(r);
	}
}

template <class T>
void PlayField::SpawnAlien()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	if (std::is_base_of<Alien, T>::value)
	{
		for (int k = 0; k < NBRALIEN; k++)
		{
			Alien* a = new Alien();
			a->pos.x = (float)xCoord(*GetrGen());
			a->pos.y = (float)yCoord(*GetrGen());
			GetWorld()->AddObject(a);
		}
	}
	return;
}

#include "Game/UndefAllStat.h"

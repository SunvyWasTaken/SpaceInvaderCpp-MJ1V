#pragma once
#include "Game/Input/Input.h"
#include "Vector.h"
#include "Game/Entity/Alien.h"

#include <vector>
#include <type_traits>

typedef std::uniform_int_distribution<int> intRand;

namespace sf
{
	class RenderWindow;
}

class GameObject;

class PlayField
{
private:

	// Current list d'objet to update.
	std::vector<GameObject*> gameObjects;
	// Object to delete the next frame.
	std::vector<GameObject*> ObjectsToDestroy;
	// Object to add on the next frame.
	std::vector<GameObject*> ObjectToAdd;

	intRand xCoord;
	intRand yCoord;

public:
	Vector2D bounds;

	// Number of available active laser slots for aliens and player
	int AlienLasers;
	int PlayerLasers;

	PlayField(Vector2D iBounds);

	const std::vector<GameObject*>& GameObjects() { return gameObjects; }

	void Update();

	GameObject* GetPlayerObject();

#pragma region Controller Input

private:
	Input* controllerInput;

public:
	Input* GetInputController() { return controllerInput; }

	void SetController(Input* InputRef);

#pragma endregion

public:

	void Init();

	void SpawnLaser(GameObject* newObj);

	void DespawnLaser(GameObject* newObj);

	void AddObject(GameObject* newObj);

	void RemoveObject(GameObject* newObj);

	bool IsShipLeft(const char* _Name);

	void QuitGame();


protected:

	void SpawnPlayer();

	template <class T>
	void SpawnAlien();

	void SpawnRock();

};

std::default_random_engine* GetrGen();

PlayField* GetWorld();

class RenderMgr* GetRender();


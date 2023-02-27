#pragma once
#include "../Input/Input.h"
#include "../Vector.h"

#include <vector>

class GameObject;

class PlayField
{
private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> ObjectToDestroy;
	// Object to add on the next frame.
	std::vector<GameObject*> ObjectToAdd;

	Input* controllerInput;

public:
	Vector2D bounds;

	// Number of available active laser slots for aliens and player
	int AlienLasers = 10;
	int PlayerLasers = 4;

	PlayField(Vector2D iBounds);
	const std::vector<GameObject*>& GameObjects() { return gameObjects; }

	void Update();

	GameObject* GetPlayerObject();

#pragma region Controller Input

	Input* GetInputController() { return controllerInput; }

	void SetController(Input* InputRef);

#pragma endregion

	void SpawnLaser(GameObject* newObj);

	void DespawnLaser(GameObject* newObj);

	void AddObject(GameObject* newObj);

	void RemoveObject(GameObject* newObj);
};
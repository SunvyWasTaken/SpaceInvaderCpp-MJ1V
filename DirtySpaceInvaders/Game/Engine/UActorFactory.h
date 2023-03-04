#pragma once
#include "Game/Entity/GameObject.h"

class UActorFactory
{
public:
	UActorFactory();

#pragma region SINGLETON
private:

	static UActorFactory* FactoryInstance;

public:
	static UActorFactory* GetFactory();

#pragma endregion

	template <class T>
	T* CreateActor();

};

template <class T>
T* UActorFactory::CreateActor()
{
	GameObject* Object = (GameObject*)(new T());
	Object->BeginPlay();
	return (T*)Object;
}
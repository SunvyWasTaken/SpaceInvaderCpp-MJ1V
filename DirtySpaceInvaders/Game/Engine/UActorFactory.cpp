#include "UActorFactory.h"

UActorFactory::UActorFactory()
{
}

UActorFactory* UActorFactory::GetFactory()
{
	if (!FactoryInstance)
	{
		return new UActorFactory();
	}
	return FactoryInstance;
}

UActorFactory* UActorFactory::FactoryInstance = nullptr;

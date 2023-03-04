#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	if (m_objType)
		delete[] m_objType;
}

void GameObject::BeginPlay()
{
}

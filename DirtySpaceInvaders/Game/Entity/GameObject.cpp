#include "GameObject.h"

GameObject::~GameObject()
{
	if (m_objType)
		delete[] m_objType;
}

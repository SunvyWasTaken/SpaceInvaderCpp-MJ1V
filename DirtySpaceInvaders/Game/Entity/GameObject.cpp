#include "GameObject.h"
#include <iostream>

#include <string>

GameObject::~GameObject()
{}

bool GameObject::IsType(const char* type)
{
	return !m_objType.compare(type);
}

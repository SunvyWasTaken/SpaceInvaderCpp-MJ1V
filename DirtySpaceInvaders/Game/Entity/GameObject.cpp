#include "GameObject.h"
#include <iostream>


GameObject::~GameObject()
{
	if (m_objType)
		delete[] m_objType;
}

bool GameObject::IsType(const char* type)
{
	return strcmp(m_objType, type) == 0;
}

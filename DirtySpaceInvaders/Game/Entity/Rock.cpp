#include "Rock.h"
#include "Game/Render/ConsoleRenderer.h"
#pragma warning(disable : 4996)

#include <string>

ARock::ARock()
{
	m_objType = new char[64];
	strcpy(m_objType, "Rock");
	sprite = RS_Rock;
}

void ARock::Update(PlayField& world)
{
}

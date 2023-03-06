#include "Rock.h"
#include "Game/Render/ConsoleRenderer.h"

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

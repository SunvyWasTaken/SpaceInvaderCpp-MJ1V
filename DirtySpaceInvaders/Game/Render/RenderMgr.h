#pragma once
#include "Game/Engine/Vector.h"

class RenderMgr
{
public:

	RenderMgr(const Vector2D& _size);
	~RenderMgr();
	
	virtual void Update() = 0;

	virtual void Draw() = 0;

};


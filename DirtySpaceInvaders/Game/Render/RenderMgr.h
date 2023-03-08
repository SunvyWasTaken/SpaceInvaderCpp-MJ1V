#pragma once
#include "Game/Engine/Vector.h"

class RenderMgr
{
public:

	RenderMgr(const Vector2D& _size);
	virtual ~RenderMgr() = default;

	bool isOpen;

	virtual void Init() = 0;
	
	virtual void Update() = 0;

	virtual void Draw() = 0;

};


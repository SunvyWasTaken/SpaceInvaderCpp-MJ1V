#pragma once

#include <vector>

#include "RenderMgr.h"
#include "Game/Engine/ERaiderSprites.h"

struct RenderItem
{
	RenderItem(const Vector2D& iPos, char iSprite) : pos(iPos), sprite(iSprite) {};
	Vector2D pos;
	char sprite;
};
typedef std::vector<RenderItem> RenderItemList;

class ConsoleRenderer : public RenderMgr
{
public:
	ConsoleRenderer(const Vector2D& bounds);
	~ConsoleRenderer();

	// Draws all game objects after clearing filling the Canvas with _ symbol
	void Update(const RenderItemList& renderList);

	void Update() override;

	void Draw() override;

	void Init() override;

private:

	unsigned GetSprite(ERaiderSprites& _sprite);

	Vector2D renderBounds;
	int curIdx = 0;
	struct
	{
		unsigned char* canvas = nullptr;
	} disp[2]; // double buffer our canvas for no flicker display

	int canvasSize = 0;
	unsigned char* CurCanvas(int x, int y) { return &disp[curIdx % 2].canvas[x + (int)renderBounds.x * y]; }

	// Fills whole canvas array with sprite
	void FillCanvas(unsigned char sprite);

};


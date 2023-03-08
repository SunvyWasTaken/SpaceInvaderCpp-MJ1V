#include <vector>
#include <iostream>
#include "ConsoleRenderer.h"
#include "Game/Engine/PlayField.h"
#include "Game/Entity/GameObject.h"

#include <Windows.h>
#include <SFML/Window/Keyboard.hpp>

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

ConsoleRenderer::ConsoleRenderer(const Vector2D& bounds)
	: RenderMgr(bounds), renderBounds(bounds)
{
	canvasSize = (int)(bounds.x * bounds.y);
	disp[0].canvas = new unsigned char[canvasSize];
	disp[1].canvas = new unsigned char[canvasSize];
}


ConsoleRenderer::~ConsoleRenderer()
{
	delete[] disp[0].canvas;
	delete[] disp[1].canvas;
}

void ConsoleRenderer::Update(const RenderItemList& RenderList)
{
	ERaiderSprites background = ERaiderSprites::RS_BackgroundTile;
	FillCanvas(' ');

	for (auto ri : RenderList)
	{
		int x = int(ri.pos.x);
		int y = int(ri.pos.y);

		if (x >= 0 && x < renderBounds.x && y >= 0 && y < renderBounds.y)
		{
			*CurCanvas((int)ri.pos.x, +(int)ri.pos.y) = ri.sprite;
		}
	}
}

void ConsoleRenderer::Update()
{
	RenderItemList rl;
	// change to character
	for (auto* it : GetWorld()->GameObjects())
	{
		RenderItem a = RenderItem(Vector2D(it->pos), GetSprite(it->sprite));
		rl.push_back(a);
	}

	Update(rl);
}

unsigned ConsoleRenderer::GetSprite(ERaiderSprites& _sprite)
{
	switch (_sprite)
	{
	case RS_BackgroundTile:
		return ' ';
		break;
	case RS_Player:
		return 'P';
		break;
	case RS_Alien:
		return 'A';
		break;
	case RS_BetterAlien:
		return 'B';
		break;
	case RS_PlayerLaser:
		return 0xBA;
		break;
	case RS_AlienLaser:
		return '|';
		break;
	case RS_Explosion:
		return '*';
		break;
	case RS_Rock:
		return 'O';
		break;
	default:
		break;
	}
	return 0;
}

void ConsoleRenderer::FillCanvas(unsigned char sprite)
{
	for (int i = 0; i < canvasSize; i++)
	{
		*CurCanvas(i, 0) = sprite;
	}
}

void ConsoleRenderer::Draw()
{
	for (int y = 0; y < renderBounds.y; y++)
	{
		for (int x = 0; x < renderBounds.x; x++)
		{
			setCursorPosition(x, y);
			std::cout << *CurCanvas(x, y);
		}
		std::cout << std::endl;
	}

	curIdx++;
}

void ConsoleRenderer::Init()
{
}


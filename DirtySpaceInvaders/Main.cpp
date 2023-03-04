#include "Game/Render/ConsoleRenderer.h"
#include "Game/Entity/Alien.h"
#include "Game/Entity/PlayerShip.h"
#include "Game/Engine/PlayField.h"

#include <random>
#include <thread>
#include <memory>
#include <string>



typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

std::default_random_engine rGen;

std::default_random_engine* GetrGen()
{
	return &rGen;
}

int main()
{
	rGen.seed(1);

	Vector2D size(80, 28);
	Renderer consoleRenderer(size);
	PlayField world(size);

	intRand xCoord(0, (int)size.x- 1);
	intRand yCoord(0, 10);

	// Populate aliens
	for (int k = 0; k < 20; k++)
	{
		Alien* a = new Alien();
		a->pos.x = (float)xCoord(rGen);
		a->pos.y = (float)yCoord(rGen);
		world.AddObject(a);
	}

	// set a controller.
	Input* CurrentInput = new PlayerInput();
	world.SetController(CurrentInput);

	// Add player
	PlayerShip* p = new PlayerShip();
	p->pos = Vector2D(40, 27);
	world.AddObject(p);

	while (true)
	{
		world.Update();

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->pos), it->sprite);
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
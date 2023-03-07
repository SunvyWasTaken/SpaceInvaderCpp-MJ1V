#include "Game/Render/ConsoleRenderer.h"
#include "Game/Entity/Alien.h"
#include "Game/Entity/Rock.h"
#include "Game/Entity/PlayerShip.h"
#include "Game/Engine/PlayField.h"
#include "Game/GameStat.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

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

	sf::RenderWindow* pWindows = new sf::RenderWindow(sf::VideoMode(1280,720), "NOT Space vader");

	// Pour L'audio.
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Ressources/Megalovania.wav"))
	{
		std::cout << "Error Load File\n";
	}
	else
	{
		sf::Sound sound;
		sound.setBuffer(buffer);
		sound.setLoop(true);
		sound.play();
	}
	

	Vector2D WorldBound = WORLDBOUND;
	Renderer consoleRenderer(WorldBound);
	PlayField world(WorldBound);

	intRand xCoord(0, (int)WorldBound.x- 1);
	intRand yCoord(0, 10);

	// Populate aliens
	for (int k = 0; k < NBRAALIEN; k++)
	{
		Alien* a = new Alien();
		a->pos.x = (float)xCoord(rGen);
		a->pos.y = (float)yCoord(rGen);
		world.AddObject(a);
	}

	// ajour des roches
	for (int i = 0; i < 10; i++)
	{
		ARock* r = new ARock();
		r->pos.x = (float)xCoord(rGen);
		r->pos.y = (float)yCoord(rGen);
		world.AddObject(r);
	}

	// set a controller.
	Input* CurrentInput = new PlayerInput();
	world.SetController(CurrentInput);

	// Add player
	PlayerShip* p = new PlayerShip();
	Vector2D PlayerSpawn = PLAYERSPAWN;
	p->pos = PlayerSpawn;
	world.AddObject(p);
#include "Game/UndefAllStat.h"

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || !world.GetPlayerObject())
		{
			exit(0);
		}
	}
}
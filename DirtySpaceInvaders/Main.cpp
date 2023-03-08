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


#define SFMLRENDER true

#if SFMLRENDER
	#include "Game/Render/RenderSFML.h"
#else
	#include "Game/Render/ConsoleRenderer.h"
#endif

typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

std::default_random_engine rGen;

std::default_random_engine* GetrGen()
{
	return &rGen;
}

PlayField* world;

PlayField* GetWorld()
{
	return world;
}

int main()
{
	rGen.seed(1);

	// Pour L'audio.
	sf::Music music;
	if (!music.openFromFile("Ressources/Megalovania.wav"))
	{
		std::cout << "Didn't work\n";
	}
	else
	{
		music.setVolume(20);
		music.setLoop(true);
		music.play();
	}
	
	Vector2D WorldBound = WORLDBOUND;
	#if SFMLRENDER
	RenderSFML RenderManager(WorldBound);
	RenderManager.Init();
	#else
	Renderer RenderManager(WorldBound);
	#endif
	#undef SFMLRENDER

	world = new PlayField(WorldBound);

	intRand xCoord(0, (int)WorldBound.x- 1);
	intRand yCoord(0, (int)WorldBound.y / 2);

	// Populate aliens
	for (int k = 0; k < NBRAALIEN; k++)
	{
		Alien* a = new Alien();
		a->pos.x = (float)xCoord(rGen);
		a->pos.y = (float)yCoord(rGen);
		world->AddObject(a);
	}

	// ajour des roches
	for (int i = 0; i < NBRROCK; i++)
	{
		ARock* r = new ARock();
		r->pos.x = (float)xCoord(rGen);
		r->pos.y = (float)yCoord(rGen);
		world->AddObject(r);
	}

	// set a controller.
	Input* CurrentInput = new PlayerInput();
	world->SetController(CurrentInput);

	// Add player
	PlayerShip* p = new PlayerShip();
	Vector2D PlayerSpawn = PLAYERSPAWN;
	p->pos = PlayerSpawn;
	world->AddObject(p);
#include "Game/UndefAllStat.h"

	while (RenderManager.isOpen)
	{
		world->Update();

		RenderManager.Update();
		RenderManager.Draw();
	}
}
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

typedef std::uniform_real_distribution<float> floatRand;

std::default_random_engine rGen;

std::default_random_engine* GetrGen()
{
	return &rGen;
}

PlayField* world = nullptr;

PlayField* GetWorld()
{
	return world;
}

RenderMgr* RenderManager = nullptr;

RenderMgr* GetRender()
{
	return RenderManager;
}

int main()
{
	rGen.seed(WORLDSEED);

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
	RenderManager = new RenderSFML(WorldBound);
	RenderManager->Init();
	#else
	RenderManager = new ConsoleRenderer(WorldBound);
	#endif
	#undef SFMLRENDER

	world = new PlayField(WorldBound);

	world->Init();

#include "Game/UndefAllStat.h"

	while (RenderManager->isOpen)
	{
		world->Update();

		RenderManager->Update();
		RenderManager->Draw();
	}
}
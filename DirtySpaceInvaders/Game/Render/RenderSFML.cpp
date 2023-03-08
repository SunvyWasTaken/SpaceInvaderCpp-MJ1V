#include "RenderSFML.h"
#include "Game/Engine/PlayField.h"
#include "Game/Entity/GameObject.h"
#include "Game/Engine/ERaiderSprites.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>


RenderSFML::RenderSFML(const Vector2D& _size) : RenderMgr(_size), pWindow(nullptr), Tampax(nullptr)
{
	Size = _size;
	Init();
}

RenderSFML::~RenderSFML()
{
	delete pWindow;
	delete Tampax;
	delete textureSheet;
}

void RenderSFML::Init()
{
	pWindow = new sf::RenderWindow(sf::VideoMode(1280,720), "NOT Space vader");
	#include "Game/GameStat.h"
	pWindow->setFramerateLimit(FRAMERATE);
	#include "Game/UndefAllStat.h"
	sf::Vector2f RectSize = sf::Vector2f(1280/Size.x, 720/ Size.y);
	Tampax = new sf::RectangleShape(sf::Vector2f(RectSize));
	textureSheet = new sf::Texture();
	if (textureSheet->loadFromFile("Ressources/GameSheet.png"))
	{
		Tampax->setTexture(textureSheet);
	}
}

void RenderSFML::Update()
{
	sf::Event event;
	while (pWindow->pollEvent(event))
	{
		if (event.KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			pWindow->close();
			isOpen = false;
		}
		if (event.type == sf::Event::Closed)
		{
			pWindow->close();
			isOpen = false;
		}
	}
}

void RenderSFML::Draw()
{	
	pWindow->clear();
	for (const auto* Object : GetWorld()->GameObjects())
	{
		sf::Vector2f Loc = sf::Vector2f((1280 * Object->pos.x) / Size.x,(720 * Object->pos.y)/Size.y);
		Tampax->setPosition(Loc);
		Tampax->setFillColor(GetSprite(Object->sprite));
		Tampax->setTextureRect(sf::IntRect(GetInRect(Object->sprite),0, 30, 30));
		pWindow->draw(*Tampax);
	}
	pWindow->display();
}

int RenderSFML::GetInRect(ERaiderSprites _sprite)
{
	switch (_sprite)
	{
	case RS_BackgroundTile: return 0;
		break;
	case RS_Player: return 30;
		break;
	case RS_Alien: return 60;
		break;
	case RS_BetterAlien: return 150;
		break;
	case RS_PlayerLaser: return 90;
		break;
	case RS_AlienLaser: return 120;
		break;
	case RS_Explosion: return 180;
		break;
	case RS_Rock: return 210;
		break;
	}
}

sf::Color RenderSFML::GetSprite(ERaiderSprites _Sprite)
{
	switch (_Sprite)
	{
	case RS_Player:
		return sf::Color::Blue;
		break;
	case RS_Alien:
		return sf::Color::Red;
		break;
	case RS_BetterAlien:
		return sf::Color::Cyan;
		break;
	case RS_PlayerLaser:
		return sf::Color::Green;
		break;
	case RS_AlienLaser:
		return sf::Color::Magenta;
		break;
	case RS_Rock:
		return sf::Color::Yellow;
		break;
	default:
		return sf::Color::Black;
		break;
		
	}
}

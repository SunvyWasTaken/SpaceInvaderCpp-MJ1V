#pragma once
#include "RenderMgr.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>



class RenderSFML :
    public RenderMgr
{
public:

    RenderSFML(const Vector2D& _size);

    ~RenderSFML();

    void Init();

    void Update();

    void Draw();

private:

    Vector2D Size;

    sf::RenderWindow* pWindow;

    sf::RectangleShape* Tampax;

    sf::Color GetSprite(enum ERaiderSprites _Sprite);
};


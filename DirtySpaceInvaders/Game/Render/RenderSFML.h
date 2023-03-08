#pragma once
#include "RenderMgr.h"

namespace sf
{
    class Color;
    class RectangleShape;
    class RenderWindow;
    class Texture;
}

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

    sf::Texture* textureSheet;

    sf::Color GetSprite(enum ERaiderSprites _Sprite);

    int GetInRect(enum ERaiderSprites _sprite);
};


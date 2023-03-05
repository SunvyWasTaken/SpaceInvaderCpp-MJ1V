#include "Input.h"
#include "Game/Engine/PlayField.h"
#include <SFML/Window/Keyboard.hpp>
#include "PlayerBind.h"

bool RndInput::Left()
{
	floatRand keyRate(0, 1);
	return (keyRate(*GetrGen()) < 0.3f);
}

bool RndInput::Right()
{
	floatRand keyRate(0, 1);
	return (keyRate(*GetrGen()) < 0.4f);
}

bool RndInput::Fire()
{
	floatRand keyRate(0, 1);
	return (keyRate(*GetrGen()) < 0.5f);
}

bool PlayerInput::Left()
{
	return sf::Keyboard::isKeyPressed(LeftKey);
}

bool PlayerInput::Right()
{
	return sf::Keyboard::isKeyPressed(RightKey);
}

bool PlayerInput::Fire()
{
	return sf::Keyboard::isKeyPressed(FireKey);
}

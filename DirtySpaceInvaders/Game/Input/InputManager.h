#pragma once

#include "PlayerInputAction.h"

#include <map>
#include <vector>
#include <functional>
#include <SFML/Window/Keyboard.hpp>

enum class FInputAction
{
	None,
	Left,
	Right,
	Shoot
};

class FInputManager final
{
public:
	void Init();
	void Update(float fDeltaTime);

	void AddNewPlayer();

	void BindAction(int playerIndex, FInputAction inputAction, std::function<void(float)> func);

private:

	struct FInputBindInfo
	{
		FInputBindInfo(unsigned playerIndex, FInputAction action);
		unsigned PlayerIndex;
		FInputAction Action;
	};

	void SetPlayerActionState(unsigned playerIndex, FInputAction action, float value);

	std::vector<PlayerInputAction> PlayersInputAction;
	std::map<sf::Keyboard::Key, FInputBindInfo> InputBinds;
};

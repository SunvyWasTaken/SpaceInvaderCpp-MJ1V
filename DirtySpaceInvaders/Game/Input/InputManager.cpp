#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>
#include <assert.h>

void FInputManager::Init()
{}

void FInputManager::Update(float fDeltaTime)
{
	for (const auto& CurrentInput : InputBinds)
	{
		const sf::Keyboard::Key& key = CurrentInput.first;
		const FInputBindInfo& bindInfo = CurrentInput.second;

		if (sf::Keyboard::isKeyPressed(key))
		{
			SetPlayerActionState(bindInfo.PlayerIndex, bindInfo.Action, 0.f);
		}
		else
		{
			SetPlayerActionState(bindInfo.PlayerIndex, bindInfo.Action, 1.f);
		}
	}
	return;
}

void FInputManager::AddNewPlayer()
{
	int index = PlayersInputAction.size();
	PlayersInputAction.push_back(PlayerInputAction(index));
	if (index == 0)
	{
		#define INIT_DEFAULT_BIND(key, bind) InputBinds.insert(std::make_pair(key, bind));
		#include "PlayerBinds.h"
		#undef INIT_DEFAULT_BIND
	}
}

void FInputManager::BindAction(int playerIndex, FInputAction inputAction, std::function<void(float)> func)
{
	PlayersInputAction[playerIndex].BindAction(inputAction, func);
}

void FInputManager::SetPlayerActionState(unsigned playerIndex, FInputAction action, float value)
{
	PlayersInputAction[playerIndex].SetInputAction(action, value);
}

FInputManager::FInputBindInfo::FInputBindInfo(unsigned playerIndex, FInputAction action) : PlayerIndex(playerIndex), Action(action)
{}

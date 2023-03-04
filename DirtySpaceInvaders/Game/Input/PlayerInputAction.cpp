#include "PlayerInputAction.h"

PlayerInputAction::PlayerInputAction(unsigned playerIndex) : PlayerIndex(playerIndex)
{
}

void PlayerInputAction::SetInputAction(FInputAction action, float value)
{
}

float PlayerInputAction::GetInputActionValue(FInputAction action) const
{
	return 0.0f;
}

bool PlayerInputAction::IsInputActionPressed(FInputAction action) const
{
	return false;
}

bool PlayerInputAction::IsInputActionReleased(FInputAction action) const
{
	return false;
}

void PlayerInputAction::BindAction(FInputAction inputAction, std::function<void(float)> func)
{
}

PlayerInputAction::InputActionInfo::InputActionInfo() : Value(0.f), Callbacks()
{
}

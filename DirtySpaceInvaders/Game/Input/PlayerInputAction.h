#pragma once

#include <map>

#include <functional>
#include <vector>

enum class FInputAction;

class PlayerInputAction final
{
public:
	PlayerInputAction(unsigned playerIndex);

	void SetInputAction(FInputAction action, float value);

	float GetInputActionValue(FInputAction action) const;

	bool IsInputActionPressed(FInputAction action) const;
	bool IsInputActionReleased(FInputAction action) const;

	void BindAction(FInputAction inputAction, std::function<void(float)> func);

private:
	unsigned PlayerIndex;

	struct InputActionInfo
	{
		InputActionInfo();

		float Value;
		std::vector<std::function<void(float)>> Callbacks;
	};

	std::map<FInputAction, InputActionInfo> InputActionsInfo;
};

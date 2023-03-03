#include "Input.h"
#include "Game/Engine/PlayField.h"

bool RndInput::Left() { floatRand keyRate(0, 1); return (keyRate(*GetrGen()) < 0.3f); }
bool RndInput::Right() { floatRand keyRate(0, 1); return (keyRate(*GetrGen()) < 0.4f); };
bool RndInput::Fire() { floatRand keyRate(0, 1); return (keyRate(*GetrGen()) < 0.5f); };
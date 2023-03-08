#include "AlienStonk.h"
#include "Game/Engine/ERaiderSprites.h"

AlienStonk::AlienStonk() : Alien()
{
#include "Game/GameStat.h"
	health = BALIENHEALTH;
	energy = BALIENENERGY;
	direction = BALIENDIRECTION;
	velocity = BALIENVELOCITY;
#include "Game/UndefAllStat.h"
	sprite = RS_BetterAlien;
}

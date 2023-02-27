#pragma once
#include <random>

static std::default_random_engine rGen;
typedef std::uniform_real_distribution<float> floatRand;

class Input
{
public:
	virtual bool Left() = 0;
	virtual bool Right() = 0;
	virtual bool Fire() = 0;
};

class RndInput : public Input
{
public:
	virtual bool Left() { floatRand keyRate(0, 1); return (keyRate(rGen) < 0.3f); }
	virtual bool Right() { floatRand keyRate(0, 1); return (keyRate(rGen) < 0.4f); };
	virtual bool Fire() { floatRand keyRate(0, 1); return (keyRate(rGen) < 0.5f); };
};
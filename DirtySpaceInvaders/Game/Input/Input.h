#pragma once
#include <random>


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
	virtual bool Left();
	virtual bool Right();
	virtual bool Fire();
};

class PlayerInput : public Input
{
	virtual bool Left();
	virtual bool Right();
	virtual bool Fire();
};
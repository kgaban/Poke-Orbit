#pragma once
#include "GameObject.h"
#include "PokeOrbitApp.h"
#include <cmath>
class CEmitter
{
public:
	CEmitter() = delete;
	CEmitter(const CEmitter &) = delete;
	CEmitter(CPokeOrbitApp*);
	virtual ~CEmitter();
	void Emit();
private:
	double timeSinceEmission;
	CPokeOrbitApp * mPokeOrbitApp;
};

